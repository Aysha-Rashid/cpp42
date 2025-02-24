#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}
void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level)
{
    int i = 0;
    std::cout << level + ": "<< std::endl;
    std::string input[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    // Each element in the func array will hold a pointer to a member function.
    //if i use harl then it will a array of objects, (debug, info etc) are not object but rather a member function
    while (i < 4)
    {
        if (level.compare(input[i]) == 0)
        {
            (this->*func[i])();
            break;
        }
        i++;
    }
}