#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>  // For std::rand() and std::srand()
#include <ctime> 
#include "AForm.hpp"
#include "Bureaucrat.hpp"
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

#endif