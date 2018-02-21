#include "framework/robot_base.hpp"

#include <istream>
#include <ostream>
#include <cppfs/FileHandle.h>
#include <cppfs/fs.h>
#include <framework/exceptions.hpp>

namespace rip
{
    namespace framework
    {
        RobotBase::RobotBase(const std::string& config)
            : m_running(false)
            , m_config_path(config)
        {
        }

        RobotBase::~RobotBase()
        {
            m_running = false;

            for (auto iter : m_subsystems)
            {
                iter.second->stop();
            }

            m_spine->stop();
        }

        void RobotBase::init()
        {
            cppfs::FileHandle config_file = cppfs::fs::open(m_config_path);
            if (!config_file.exists())
            {
                throw FileNotFound();
            }

            std::unique_ptr<std::istream> in = config_file.createInputStream();
            nlohmann::json j;
            (*in) >> j;
            std::vector<std::string> devices;
            for (nlohmann::json d : j["devices"])
            {
                std::string device_name = d;
                devices.push_back(device_name);
            }

            m_spine = std::unique_ptr<Spine>(new Spine);
            m_spine->loadDevices(j["arduino_gen_home"], devices);

            createSubsystems(j);

            createRoutine();

            m_state_file = cppfs::fs::open(j["state_file"]).createOutputStream();
        }

        void RobotBase::start()
        {
            m_running = true;
            m_thread = std::unique_ptr<std::thread>(new std::thread(&RobotBase::run, this));
        }

        void RobotBase::stop()
        {
            m_running = false;
        }

        void RobotBase::run()
        {
            nlohmann::json state;

            // Loop through the routine
            for (std::shared_ptr<Action> action : m_routine)
            {
                // If ever interrupted then stop
                if (!m_running)
                {
                    break;
                }

                // Setup the action
                action->setup(state);

                // Reset the state file
                m_state_file->clear();
                (*m_state_file) << state;
                m_state_file->flush();

                // If ever interrupted then stop
                if (!m_running)
                {
                    break;
                }

                // Update until the action is finished
                while (m_running && !action->isFinished())
                {
                    action->update(state);

                    // Reset the state file
                    m_state_file->clear();
                    (*m_state_file) << state;
                    m_state_file->flush();

                    // std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(m_update_time.to(units::ms))));
                }

                // If ever interrupted then stop
                if (!m_running)
                {
                    break;
                }

                action->teardown(state);

                // Reset the state file
                m_state_file->clear();
                (*m_state_file) << state;
                m_state_file->flush();
            }
            m_running = false;
        }
    }
}
