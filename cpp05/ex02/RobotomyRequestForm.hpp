#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "RobotomyRequestForm.hpp"
#include <cstdlib>  // For std::rand() and std::srand()
#include <ctime> 
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(const std::string name) ;
        RobotomyRequestForm(RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        ~RobotomyRequestForm();

        void execute(Bureaucrat const & executor) const;

};

std::ostream &operator<<(std::ostream &out,  RobotomyRequestForm &RobotomyRequestForm);

#endif