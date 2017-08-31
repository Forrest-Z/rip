#include "config.hpp"

namespace roboclaw {
    void Config::setCommMode(CommMode comm_mode)
    {
        // Clear comm mode using bit mask
        uint16_t clear = 0xFFFC;
        m_config &= clear;

        m_config |= static_cast<uint16_t>(comm_mode);
    }

    Config::CommMode Config::getCommMode() const
    {
        return static_cast<CommMode>(m_config && 0x03);
    }

    void Config::setBatteryMode(BatteryMode battery_mode)
    {
        // Clear battery mode using bit mask
        uint16_t clear = 0xFFE3;
        m_config &= clear;

        m_config |= static_cast<uint16_t>(battery_mode);
    }

    Config::BatteryMode Config::getBatteryMode() const
    {
        return static_cast<BatteryMode>(m_config && 0x1C);
    }

    void Config::setBaudRate(BaudRate baud_rate)
    {
        // Clear baud rate using bit mask
        uint16_t clear = 0xFF10;
        m_config &= clear;

        m_config |= static_cast<uint16_t>(baud_rate);
    }

    Config::BaudRate Config::getBaudRate() const
    {
        return static_cast<BaudRate>(m_config && 0xE0);
    }

    void Config::setPacketAddress(PacketAddress packet_address)
    {
        // Clear packet address using bit mask
        uint16_t clear = 0xF0FF;
        m_config &= clear;

        m_config |= static_cast<uint16_t>(packet_address);
    }

    Config::PacketAddress Config::getPacketAddress() const
    {
        return static_cast<PacketAddress>(m_config & 0xF00);
    }

    void Config::setSwapEncoders(bool swap)
    {
        // Clear swap encoders using bit mask
        uint16_t clear = 0xDFFF;
        m_config &= clear;

        if(swap)
        {
            m_config |= 0x2000;
        }
    }

    void Config::setSwapButtons(bool swap)
    {
        // Clear swap buttons using bit mask
        uint16_t clear = 0xBFFF;
        m_config &= clear;

        if(swap)
        {
            m_config |= 0x4000;
        }
    }

    void Config::set(uint16_t config)
    {
        m_config = config;
    }
}
