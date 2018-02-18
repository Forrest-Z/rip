#ifndef _PERIPHERY_I2C_HPP
#define _PERIPHERY_I2C_HPP

extern "C"
{
    #include "i2c.h"
}
#include "peripherycpp/exceptions.hpp"
#include <vector>
#include <string>

namespace rip
{

    namespace peripherycpp
    {

        class I2c 
        {
            public:

                void open(const std::string path);

                void transfer(std::vector< std::vector<uint8_t> > msg_data, std::vector<int> flags, size_t count);

                void close();

                int fd();

                std::string toString(size_t len);

            private:

                i2c_t i2c;

        };

    }

}

#endif
