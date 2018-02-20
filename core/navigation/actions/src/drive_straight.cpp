#include "navigation_actions/drive_straight.hpp"

#include <chrono>

namespace rip
{
    namespace navigation
    {
        namespace actions
        {
            DriveStraight::DriveStraight(std::shared_ptr<drivetrains::Drivetrain> drivetrain, const units::Distance& distance, double p, double i, double d)
                : m_use_time(false)
                , m_distance(distance)
                , m_drivetrain(drivetrain)
            {}

            DriveStraight::DriveStraight(std::shared_ptr<drivetrains::Drivetrain> drivetrain, const units::Time& time, const units::Velocity& speed)
                : m_use_time(true)
                , m_time(time)
                , m_speed(speed)
                , m_drivetrain(drivetrain)
            {}

            bool DriveStraight::isFinished()
            {
                return std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count() * units::ms - m_start_time > m_time;
            }

            void DriveStraight::update(nlohmann::json& state)
            {
                return;
            }

            void DriveStraight::setup(nlohmann::json& state)
            {
                m_start_time = std::chrono::duration_cast< std::chrono::milliseconds >(
                                   std::chrono::system_clock::now().time_since_epoch()).count() * units::ms;
                //m_drivetrain->drive(drivetains::NavCommand(m_speed, 0));
            }

            void DriveStraight::teardown(nlohmann::json& state)
            {
                m_drivetrain->stop();
            }
        }
    }
}