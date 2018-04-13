#include "framework/timeout_action.hpp"

namespace rip
{
    namespace framework
    {

        TimeoutAction::TimeoutAction(const std::string& name, const nlohmann::json& config)
            : Action(name)
        {
            if (config.find("timeout") == config.end())
            {
                m_has_timeout = false;
            }
            else
            {
                m_timeout = config["timeout"];
                misc::Logger::getInstance()->debug(fmt::format("TimeoutAction setup with {}ms timeout value.", m_timeout.to(units::ms)));
                if(m_timeout > 0)
                {
                    m_has_timeout = true;
                }
                else
                {
                    m_has_timeout = false;
                }
            }
        }

        bool TimeoutAction::isFinished()
        {
            return m_has_timeout && (units::now() > (m_start_time + m_timeout));
        }

        void TimeoutAction::update(nlohmann::json& state)
        {
            return;
        }

        void TimeoutAction::setup(nlohmann::json& state)
        {
            m_start_time = units::now();
        }

        void TimeoutAction::teardown(nlohmann::json& state)
        {
            return;
        }

    }
}