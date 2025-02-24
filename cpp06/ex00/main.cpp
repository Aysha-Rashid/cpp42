#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    std::string input;
    if (argc == 1)
    {
        std::cout << "Enter a literal to convert (e.g., '42', '42.0', 'a', 'hello'): ";
        std::cin >> input;
        if (std::cin.eof())
            return 1;
    }
    else
        input = argv[1];
    ScalarConverter::convert(input);

    return 0;
}
