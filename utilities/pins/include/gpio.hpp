#ifndef GPIO_HPP
#define GPIO_HPP

namespace rip
{
    namespace utilites
    {
        namespace pins
        {
            namespace gpio
            {
                enum class DigitalPinValue
                {
                    kLow = 0,
                    kHigh = 1
                };


                enum class DigitalPinMode
                {
                    kOutput,
                    kInput
                };

                /**
                 *
                 */
                void setPinMode(uint8_t pin, DigitalPinMode mode);

                /**
                 * [digitalWrite description]
                 * @param pin   [description]
                 * @param value [description]
                 */
                void digitalWrite(uint8_t pin, DigitalPinValue value);

                /**
                 * [digitalRead description]
                 * @param  pin [description]
                 * @return     [description]
                 */
                DigitalPinValue digitalRead(uint8_t pin);
            } // gpio
        } // pins
    } // utilities
} // rip

#endif // GPIO_HPP