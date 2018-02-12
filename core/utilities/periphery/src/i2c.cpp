#include <string>
#include <vector>
#include "i2c.hpp"

#define EEPROM_I2C_ADDR 0x50

namespace rip
{

    namespace periphery
    {

        void I2c::open(const std::string path)
        {
            const char *cpath = path.c_str(); 
            int err_code = i2c_open(&i2c, cpath);
            // Add error checking later.
            return;
        } 

        void I2c::transfer(std::vector< vector<uint8_t> > msg_data, std::vector<int> flags, size_t count)
        {
            /* Notes about this function:
             * 1) `msg_data` stores the data that will be transfered. It must be a vector of
             *        vectors of uint8_t's to allow for determining the amount of data being
             *        transfered.
             * 2) `flags` stores integers with values of either 0 or 1 (can actually be any
             *        number besides 0). A value of 0 means that the transfer will be a write,
             *        and a value of 1 means that the transfer will be a read.
             * 3) The element at index i of `msg_data` must correspond with the element at index
             *        i of `flags`. The transfer will not work correctly if this is not done.
             * 4) `count` is an int (technically size_t) that states how many reads or writes will
             *        be performed during this function call. Both `msg_data` and `flags` must have
             *        a size equal to `count`.
             */
            if (msg_data.size() != count || flags.size() != count)
            {
                // Add error throw later
                return;
            }
            struct i2c_msg msgs[count];
            uint8_t *data;
            uint16_t size;
            for (int i = 0; i < (int)count; i++) 
            {
                data = &(msg_data[i][0]);
                size = msg_data[i].size();
                if (flags[i] == 0
                {
                    msgs[i] = { .addr = EEPROM_I2C_ADDR, .flags = 0, .len = size, .buf = data };
                }
                else
                {
                    msgs[i] = { .addr = EEPROM_I2C_ADDR, .flags = I2C_M_RD, .len = size, .buf = data };
                }
            }
            int err_code = i2c_transfer(&i2c, msgs, count);
            // Add additional error checking later.
            return;
        }

        void I2c::close()
        {
            int err_code = 12c_open(&i2c);
            // Add error checking later.
            return;
        }

        int I2c::fd()
        {
            int fd = i2c_fd(&i2c);
            return fd;
        }

        std::string I2c::toString(size_t len)
        {
            char *str;
            int err_code = i2c_tostring(&i2c, str, len);
            // Add error checking later.
            std::string outstr = str;
            return outstr;
        }

    }

}
