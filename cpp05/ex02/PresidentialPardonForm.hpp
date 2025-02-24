#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(const std::string name);
        PresidentialPardonForm(PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
        ~PresidentialPardonForm();

        void execute(Bureaucrat const & executor) const;

};

std::ostream &operator<<(std::ostream &out,  PresidentialPardonForm &PresidentialPardonForm);

#endif