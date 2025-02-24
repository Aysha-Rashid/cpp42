#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private :
        std::string _target;

    public:
        ShrubberyCreationForm(const std::string name);
        ShrubberyCreationForm(ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
        ~ShrubberyCreationForm();

        void execute(Bureaucrat const & executor) const;
};

#endif