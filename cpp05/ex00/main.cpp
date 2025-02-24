#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bureaucrat1("Alice", 150);
        std::cout << bureaucrat1;
        bureaucrat1.decrement();
        std::cout << bureaucrat1;

        Bureaucrat bureaucrat2("John", 149);
        std::cout << bureaucrat2;
        bureaucrat2.decrement();
        std::cout << bureaucrat2;

        Bureaucrat bureaucrat3("Marry", 151);
        std::cout <<  bureaucrat3;
        bureaucrat3.decrement();
        std::cout << bureaucrat3;
    }
    catch (std::exception &error) {
        std::cerr << "Exception caught: " << error.what() << std::endl;
    }
}