#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string name) : AForm(name, 72, 45) , _target(name)
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm("RobotomyRequestForm", 25, 5)
{
	this->_target = copy._target;
	std::cout << "Copy RobotomyRequestForm Constuctor is being called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	std::cout << "Copy RobotomyRequestForm Assignment Constructor is Called" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Default RobotomyRequestForm destructor called" << std::endl;
}


void RobotomyRequestForm::execute(Bureaucrat const &executor) const 
{
    if (executor.getGrade() > getExecute())
		throw AForm::GradeTooLowException();
	else if (!getSigned())
		throw AForm::GradeNotSigned();

	int	success;
	srand((unsigned) time(NULL));
	success = rand() % 2;
	if (success)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << "'s robotomization failed" << std::endl;
}

std::ostream &operator<<(std::ostream &out,  RobotomyRequestForm &RobotomyRequestForm)
{
	out << RobotomyRequestForm.getName() << ", needs to have sign grade:  " << RobotomyRequestForm.getGradeSigned() << 
		 " to sign the RobotomyRequestForm and have the execute grade: " 
		<< RobotomyRequestForm.getExecute()  << " to execute the RobotomyRequestForm " << std::endl;
	return out;
}