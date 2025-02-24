#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(ScalarConverter &copy){*this = copy;}
ScalarConverter &ScalarConverter::operator=(ScalarConverter &copy){(void)copy; return (*this);}
void ScalarConverter::convert(const std::string& literals)
{
    if (literals.empty())
        return;
    if (literals.length() == 1 && !std::isdigit(literals[0])) {
        char ch = literals[0];
        std::cout << "the type is Char data" << std::endl;
        std::cout << "char: '" << static_cast<unsigned char>(ch) << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(ch) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(ch) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(ch) << "f" << std::endl;
        return;
    }
    char* end;
    if (literals.find('.') == std::string::npos)
    {
        int value = strtol(literals.c_str(), &end, 10);
        if (*end != '\0' && *end != 'f') {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << literals <<  "f" << std::endl;
                std::cout << "double: " << literals << std::endl;
            return ;
        }
        std::cout << "the type is Int data" << std::endl;
        if (std::isprint(static_cast<unsigned char>(value))) {
                std::cout << "char: '" << static_cast<unsigned char>(value) << "'" << std::endl;
            } else {
                std::cout << "char: Non displayable" << std::endl;
            }        
        std::cout << "int: " << value << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(value) << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
    else
    {
        if (literals.find('f') == std::string::npos)
        {
            double value = strtod(literals.c_str(), &end);
            if (*end != '\0' && *end != 'f') {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << literals <<  "f" << std::endl;
                std::cout << "double: " << literals << std::endl;
                return ;
            }
            std::cout << "the type is Double data" << std::endl;
            if (std::isprint(static_cast<unsigned char>(value))) {
                    std::cout << "char: '" << static_cast<unsigned char>(value) << "'" << std::endl;
                } else {
                    std::cout << "char: Non displayable" << std::endl;
                }
            std::cout << "int: " << static_cast<int>(value) << std::endl;
            std::cout << std::fixed << std::setprecision(1) << "double: " << value << std::endl;
            std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(value) << "f" << std::endl;
        }
        else
        {
            float value = strtof(literals.c_str(), &end);
            if (*end != '\0' && *end != 'f') {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << literals <<  "f" << std::endl;
                std::cout << "double: " << literals << std::endl;
                return ;
            }
            std::cout << "the type is Float data" << std::endl;
            if (std::isprint(static_cast<unsigned char>(value))) {
                    std::cout << "char: '" << static_cast<unsigned char>(value) << "'" << std::endl;
                } else {
                    std::cout << "char: Non displayable" << std::endl;
                }
            std::cout << "int: " << static_cast<int>(value) << std::endl;
            std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(value) << std::endl;
            std::cout << std::fixed << std::setprecision(1) << "float: " << value << "f" << std::endl;
        }
    }
}
