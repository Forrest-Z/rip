#ifndef _PERIPHERY_SERIAL_HPP
#define _PERIPHERY_SERIAL_HPP
#include <string>
#include <vector>
#include "peripherycpp/exceptions.hpp"

extern "C"
{
    #include "serial.h"
}

namespace rip
{
    namespace peripherycpp
    {
        class Serial
        {
        public:
            /**
             * open
             * @param device   tty device at the specified path (e.g. "/dev/ttyUSB0")
             * @param baudrate device baudrate (ie, 115200).
             * @brief
             */
            void open(std::string device, unsigned int baudrate);
            /**
             * [open description]
             * @param device   tty device at the specified path (e.g. "/dev/ttyUSB0")
             * @param baudrate baudrate device baudrate (ie, 115200).
             * @param databits databits can be 5, 6, 7, or 8
             * @param parity   parity can be PARITY_NONE, PARITY_ODD, or PARITY_EVEN
             * @param stopbits can be 1 or 2
             * @param xonxoff  [description]
             * @param rtscts   [description]
             * @brief Open the tty device at the specified path (e.g. "/dev/ttyUSB0"),
             * with the specified baudrate, data bits, parity, stop bits, software flow control (xonxoff),
             * and hardware flow control (rtscts) settings.
             */
            void open(std::string device, unsigned int baudrate, unsigned int databits,
                      int parity, unsigned int stopbits,
                      bool xonxoff, bool rtscts);
            /**
             * @brief Reads len number of bytes via serial
             * @param  len        number of bytes to read
             * @param  timeout_ms length of timeout period in ms
             * @return            vector of bytes
             */
            std::vector<uint8_t> read(size_t len, int timeout_ms);
            /**
             * @brief writes data
             * @param data vector of bytes to be written
             */
            void write(std::vector<uint8_t> data);

            void flush();

            void outputWaiting(unsigned int *count); 

            void inputWaiting(unsigned int *count);

            void poll(int timeout_ms);

            void close();

            uint32_t getBaudrate();

            unsigned int getDatabits();

            int getParity();

            unsigned int getStopbits();

            bool getxOnxOff();

            bool getRtscts();

            void setBaudrate(uint32_t baudrate);

            void setDatabits(unsigned int databits);

            void setParity(int parity);

            void setxOnxOff(bool enabled);

            void setRtscts(bool enabled);

        private:

            serial_t m_serial;
        };
    }
}

#endif