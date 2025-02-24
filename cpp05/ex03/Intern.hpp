#ifndef INTERN_HPPP
#define INTERN_HPPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Bureaucrat;
class Form;

class Intern
{
    private:
        std::string _target;

    public:
        Intern();
        Intern(Intern &copy);
        Intern &operator=(const Intern &copy);
        ~Intern();

        class NoFormFound : public std::exception {
        public:
            virtual const char* what() const throw ();
        };
        AForm *makeForm(std::string form, std::string target);        
};

#endif