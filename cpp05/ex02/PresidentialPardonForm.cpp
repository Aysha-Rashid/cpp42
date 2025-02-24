#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string name) : AForm(name, 25, 5) , _target(name)
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = copy._target;
	std::cout << "Copy PresidentialPardonForm Constuctor is being called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	std::cout << "Copy PresidentialPardonForm Assignment Constructor is Called" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Default PresidentialPardonForm destructor called" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecute())
		throw AForm::GradeTooLowException();
	else if (!getSigned())
		throw AForm::GradeNotSigned();
	else
		std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &out,  PresidentialPardonForm &PresidentialPardonForm)
{
	out << PresidentialPardonForm.getName() << ", needs to have sign grade:  " << PresidentialPardonForm.getGradeSigned() << 
		 " to sign the PresidentialPardonForm and have the execute grade: " 
		<< PresidentialPardonForm.getExecute()  << " to execute the PresidentialPardonForm " << std::endl;
	return out;
}