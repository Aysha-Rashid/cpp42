#include "Harl.hpp"

int main(void)
{
    Harl guy;
    std::string level;

    // std::cout <<"Enter the level: "; std::cin >> level;
    guy.complain("DEBUG");
    guy.complain("INFO");
    guy.complain("WARNING");
    guy.complain("ERROR");
    guy.complain("INCORRECT");
}