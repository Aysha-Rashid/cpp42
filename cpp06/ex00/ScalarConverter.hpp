#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
class ScalarConverter {
public:
    static void convert(const std::string& literals);
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter &copy);
    ScalarConverter &operator=(ScalarConverter &copy);
    ~ScalarConverter();
};


#endif