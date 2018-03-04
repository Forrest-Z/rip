#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

#include "mock_roboclaw.hpp"

namespace rip
{
    namespace motorcontrollers
    {
        namespace roboclaw
        {
            namespace mocks
            {
                MockRoboclaw::MockRoboclaw(nlohmann::json config, bool test) : Roboclaw(config, test)
                {}

                std::string MockRoboclaw::getLastSent()
                {
                    return m_last_sent;
                }

                void MockRoboclaw::setcResponse(const std::vector<uint8_t> response)
                {
                    m_cresponse = response;
                }

                std::vector<uint8_t> MockRoboclaw::readN(uint8_t n, Command cmd)
                {
                    return m_cresponse;
                }
                void MockRoboclaw::write(std::vector<uint8_t> data)
                {
                    m_last_cmd = data;
                }
                std::vector<uint8_t> MockRoboclaw::read(size_t len, int timeout_ms)
                {
		    std::vector<uint8_t> tmp = {0};
                    return tmp;
                }
                void MockRoboclaw::setBytes(size_t bytes)
                {
                    m_bytes = bytes;
                }

                uint8_t MockRoboclaw::returnFF()
                {
                    return m_bytes;
                }

                std::vector<uint8_t> MockRoboclaw::getLastCmd()
                {
                    return m_last_cmd;
                }

                //debugging tool for me, will remove eventually
                void MockRoboclaw::printResponse()
                {
                    if (m_last_cmd.size() == 0)
                    {
                        // std::cout << "vector empty" << std::endl;
                        return;
                    }
                    for (std::vector<uint8_t>::const_iterator i = m_last_cmd.begin(); i != m_last_cmd.end(); i++)
                    {
                        // std::cout << std::hex << static_cast<int>(*i) << ' ';
                    }
                }

            }
        }
    }
}
#pragma GCC diagnostic pop
