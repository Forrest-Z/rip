#include "appendages/roboclaw.hpp"
#include <ctime>
#include <utility>
#include <tuple>
#include <memory>
#include <chrono>
#include <thread>
#include <cmd_messenger/cmd_messenger.hpp>

#include "appendages/exceptions.hpp"

namespace rip
{
	namespace appendages
	{
		Roboclaw::Roboclaw(const nlohmann::json& config, const std::map<std::string, int>& command_map, std::shared_ptr<cmdmessenger::Device> device)
			: Appendage(config, device),
			m_set_m1_speed(createCommand("kSetM1Speed", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_set_m2_speed(createCommand("kSetM2Speed", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_set_m1m2_speed(createCommand("kSetM1M2Speed", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_set_m1_speed_accel(createCommand("kSetM1SpeedAccel", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_set_m2_speed_accel(createCommand("kSetM2SpeedAccel", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_set_m1m2_speed_accel(createCommand("kSetM1M2SpeedAccel", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_set_m1_speed_dist(createCommand("kSetM1SpeedDist", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_set_m2_speed_dist(createCommand("kSetM2SpeedDist", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_set_m1m2_speed_dist(createCommand("kSetM1M2SpeedDist", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_set_m1_speed_accel_dist(createCommand("kSetM1SpeedAccelDist", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_set_m2_speed_accel_dist(createCommand("kSetM2SpeedAccelDist", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_set_m1m2_speed_accel_dist(createCommand("kSetM1M2SpeedAccelDist", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_set_m1m2_speed_accel_decel_dist(createCommand("kSetM1M2SpeedAccelDist", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_read_m1_encoder(createCommand("kReadM1Encoder", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType>())),
			m_read_m2_encoder(createCommand("kReadM2Encoder", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType>())),
			m_read_m1m2_encoder(createCommand("kReadM1M2Encoder", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType>())),
			m_read_encoder_result(createCommand("kReadEncoderResult", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_read_encoders_result(createCommand("kReadEncodersResult", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_read_m1_encoder_speed(createCommand("kReadM1Encoder", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType>())),
			m_read_m2_encoder_speed(createCommand("kReadM2Encoder", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType>())),
			m_read_m1m2_encoder_speed(createCommand("kReadM1M2Encoder", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType>())),
			m_read_encoder_speed_result(createCommand("kReadEncoderSpeedResult", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_read_encoders_speed_result(createCommand("kReadEncodersSpeedResult", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::UnsignedLongType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>())),
			m_set_m1_duty(createCommand("kSetM1Duty", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedIntegerType>())),
			m_set_m2_duty(createCommand("kSetM2Duty", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedIntegerType>())),
			m_set_m1m2_duty(createCommand("kSetM1M2Duty", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedIntegerType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedIntegerType>())),
			m_set_velocity_pid(createCommand("kSetVelocityPID", command_map,
				cmdmessenger::ArduinoCmdMessenger::makeArgumentString<cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::CharType,
				cmdmessenger::ArduinoCmdMessenger::FloatType,
				cmdmessenger::ArduinoCmdMessenger::FloatType,
				cmdmessenger::ArduinoCmdMessenger::FloatType,
				cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>()))
		{
			if (config.find("address") == config.end())
			{
				throw AppendageMissingField(fmt::format("appendage roboclaw missing address"));
			}
			m_address = config["address"];
			if (config.find("wheel_radius") == config.end())
			{
				throw AppendageMissingField(fmt::format("appendage roboclaw missing wheel radius"));
			}
			m_wheel_radius = config.at("wheel_radius");
			if (config.find("ticks_per_rev") == config.end())
			{
				throw AppendageMissingField(fmt::format("appendage roboclaw missing address"));
			}
			m_ticks_per_rev = config.at("ticks_per_rev");

		}

		std::shared_ptr<Appendage> Roboclaw::create(const nlohmann::json& config, const std::map<std::string, int>& command_map, std::shared_ptr<cmdmessenger::Device> device)
		{
			return std::dynamic_pointer_cast<Appendage>(std::shared_ptr<Roboclaw>(new Roboclaw(config, command_map, device)));
		}

		void Roboclaw::setM1Speed(int32_t speed)
		{

		}

		void Roboclaw::setM2Speed(int32_t speed)
		{

		}

		void Roboclaw::setM1M2Speed(int32_t speed)
		{

		}

		void Roboclaw::setM1SpeedAccel(uint32_t accel, int32_t speed)
		{

		}

		void Roboclaw::setM2SpeedAccel(int32_t accel, int32_t speed)
		{

		}

		void Roboclaw::setM1M2SpeedAccel(int32_t accel, int32_t speed1, int32_t speed2)
		{

		}

		void Roboclaw::setM1SpeedDist(int32_t speed, uint32_t distance)
		{

		}

		void Roboclaw::setM2SpeedDist(int32_t speed, uint32_t distance)
		{

		}

		void Roboclaw::setM1M2SpeedDist(int32_t speed1, uint32_t distance1, int32_t speed2, uint32_t distance2)
		{

		}

		void Roboclaw::setM1SpeedAccelDist(uint32_t accel, int32_t speed, uint32_t distance)
		{

		}

		void Roboclaw::setM2SpeedAccelDist(uint32_t accel, int32_t speed, uint32_t distance)
		{

		}

		void Roboclaw::setM1M2SpeedAccelDist(uint32_t accel, int32_t speed1, uint32_t distance1, int32_t speed2, uint32_t distance2)
		{

		}

		void Roboclaw::setM1SpeedAccelDecelDist(uint32_t accel, int32_t speed,uint32_t deccel,uint32_t position)
		{

		}

		void Roboclaw::setM2SpeedAccelDecelDist(uint32_t accel, int32_t speed,uint32_t deccel,uint32_t position)
		{

		}

		void Roboclaw::setM2SpeedAccelDecelDist(uint32_t accel, int32_t speed,uint32_t deccel,uint32_t position)
		{

		}

		int32_t Roboclaw::readM1Encoder()
		{

		}

		int32_t Roboclaw::readM2Encoder()
		{

		}

		std::array<int32_t, 2> Roboclaw::readM1M2Encoders()
		{

		}

		units::Distance Roboclaw::readEncoder(bool motor)
		{
			cmdmessenger::ArduinoCmdMessenger messenger;
		}

		int32_t Roboclaw::readM1EncoderSpeed()
		{

		}

		int32_t Roboclaw::readM2EncoderSpeed()
		{

		}

		std::array<int32_t, 2> Roboclaw::readM1M2EncoderSpeed()
		{

		}

		std::array<units::Velocity, 2> Roboclaw::readEncoderSpeeds()
		{

		}

		void Roboclaw::resetEncoders()
		{

		}

		units::Velocity Roboclaw::readEncoderSpeed(bool motor)
		{

		}
		/*
		void Roboclaw::setSpeed(int32_t speed1, int32_t speed2)
		{
			cmdmessenger::ArduinoCmdMessenger messenger;
			messenger.send<cmdmessenger::ArduinoCmdMessenger::CharType, cmdmessenger::ArduinoCmdMessenger::UnsignedLongType, cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>(m_device, m_set_speed, m_address, speed1, speed2);
		}

		void Roboclaw::setSpeedAccel(int32_t accel, int32_t speed1, int32_t speed2)
		{
			cmdmessenger::ArduinoCmdMessenger messenger;
			messenger.send<cmdmessenger::ArduinoCmdMessenger::CharType, cmdmessenger::ArduinoCmdMessenger::UnsignedLongType, cmdmessenger::ArduinoCmdMessenger::UnsignedLongType, cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>(m_device, m_set_speed_accel, m_address, accel, speed1, speed2);
		}

		std::array<units::Distance, 2> Roboclaw::readEncoders()
		{
			cmdmessenger::ArduinoCmdMessenger messenger;
			messenger.send<cmdmessenger::ArduinoCmdMessenger::CharType>(m_device, m_read_encoders, m_address);
			return messenger.receive<cmdmessenger::ArduinoCmdMessenger::UnsignedLongType, cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>(m_read_encoders_result);
		}
		*/

		void Roboclaw::setDynamic(bool motor, const MotorDynamics& dynamics, bool respectBuffer)
		{
			cmdmessenger::ArduinoCmdMessenger messenger;
			int32_t speed;
            uint32_t accel, dist, decel;

			switch(dynamics.getDType())
			{
				case MotorDynamics::DType::kNone:
                {
					return;
				}
				case MotorDynamics::DType::kSpeed:
                {
					speed = static_cast<int32_t>((*dynamics.getSpeed() / (m_wheel_radius * M_PI * 2)).to(1 / units::s) * m_ticks_per_rev);

				}
				case MotorDynamics::DType::kSpeedAccel:
				{
					speed = static_cast<int32_t>((*dynamics.getSpeed() / (m_wheel_radius * M_PI * 2)).to(1 / units::s) * m_ticks_per_rev);
					accel = static_cast<uint32_t>((*dynamics.getAcceleration() / (m_wheel_radius * M_PI * 2)).to(1 / (units::s * units::s)) * m_ticks_per_rev);

				}
				case MotorDynamics::DType::kSpeedDist:
				{

				}
				case MotorDynamics::DType::kSpeedAccelDist:
                {

				}
				case MotorDynamics::DType::kSpeedAccelDecelDist:
                {

				}
				default:
				{
					assert(false);
				}
			}
		}

		void Roboclaw::setDynamics(const MotorDynamics& dynamics, bool respectBuffer);
		{
			cmdmessenger::ArduinoCmdMessenger messenger;
			int32_t speed;
            uint32_t accel, dist, decel;

			switch(dynamics.getDType())
			{
				case MotorDynamics::DType::kNone:
                {

				}
				case MotorDynamics::DType::kSpeed:
                {

				}
				case MotorDynamics::DType::kSpeedAccel:
				{
					messenger.send<cmdmessenger::ArduinoCmdMessenger::CharType, cmdmessenger::ArduinoCmdMessenger::UnsignedLongType, cmdmessenger::ArduinoCmdMessenger::UnsignedLongType, cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>(m_device, m_set_speed_accel, m_address, accel, speed1, speed2);
				}
				case MotorDynamics::DType::kSpeedDist:
				{

				}
				case MotorDynamics::DType::kSpeedDist:
                {

				}
				case MotorDynamics::DType::kSpeedAccelDist:
                {

				}
				case MotorDynamics::DType::kSpeedAccelDecelDist:
                {

				}
				default:
				{
					assert(false);
				}
			}
		}

		std::array<uint8_t, 2> Roboclaw::getBuffers();
		{
			cmdmessenger::ArduinoCmdMessenger messenger;
		}
		/*
		void Roboclaw::setDuty(int16_t duty1, int16_t duty2)
		{
			cmdmessenger::ArduinoCmdMessenger messenger;
			messenger.send<cmdmessenger::ArduinoCmdMessenger::CharType, cmdmessenger::ArduinoCmdMessenger::UnsignedIntegerType, cmdmessenger::ArduinoCmdMessenger::UnsignedIntegerType>(m_device, m_set_duty, m_address, duty1, duty2);
		}*/

		void Roboclaw::setVelocityPID(uint8_t motor, float Kp, float Ki, float Kd, uint32_t qpps)
		{
			cmdmessenger::ArduinoCmdMessenger messenger;
			messenger.send<cmdmessenger::ArduinoCmdMessenger::CharType, cmdmessenger::ArduinoCmdMessenger::CharType, cmdmessenger::ArduinoCmdMessenger::FloatType, cmdmessenger::ArduinoCmdMessenger::FloatType, cmdmessenger::ArduinoCmdMessenger::FloatType, cmdmessenger::ArduinoCmdMessenger::UnsignedLongType>(m_device, m_set_velocity_pid, m_address, motor, Kp, Ki, Kd, qpps);
		}

		void Roboclaw::stop()
		{
			setDuty(0, 0);
		}

		bool Roboclaw::diagnostic()
		{
			/*
			std::chrono::time_point<std::chrono::system_clock> start_time = std::chrono::system_clock::now();
			misc::Logger::getInstance()->debug("Roboclaw appendage diagnostics start");

			misc::Logger::getInstance()->debug("Read encoders for 10s in a loop");
			while(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start_time).count() < 10000)
			{
				misc::Logger::getInstance()->debug(fmt::format("Encoder 1 Ticks: {} | Encoder 2 Ticks: ", std::get<0>(ReadEncoders()), std::get<0>(ReadEncoders())));
			}
			misc::Logger::getInstance()->debug("Setting Duty to ~1/2 Power, forward for 5 seconds");
			SetDuty(16000, 16000);
			start_time = std::chrono::system_clock::now();
			while(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start_time).count() < 5000)
			{}
			stop();
			misc::Logger::getInstance()->debug("Setting speed accel drive (5s)");
			SetSpeedAccel(12000, 12000, 12000);
			while(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start_time).count() < 5000)
			{}
			stop();
			*/
		}
	}
}
