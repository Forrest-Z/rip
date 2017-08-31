#ifndef ARGUMENT_HPP
#define ARGUMENT_HPP

#include <string>
#include <vector>
#include <memory>

namespace tinyxml2
{
    class XMLElement;
} // tinyxml2


namespace arduinogen
{
    class Appendage;

    /**
     * @class Argument
     * @brief
     */
    class Argument
    {
    public:

        /**
         * @brief Default Constructor
         */
        Argument() = default;

        /**
         * @brief Constructor
         *
         * @param xml The xml element to parse for this argument
         */
        Argument(tinyxml2::XMLElement* xml);

        /**
         * @brief Creates the code for a single argument in a constructor
         * @param  appendage The appendage used for the single constructor
         * @return The code for a single argument in a constructor
         */
        std::string toString(std::shared_ptr<Appendage> appendage) const;

    private:
        std::string m_name;
        std::string m_type;
    };
} // arduinogen

#endif // ARGUMENT_HPP