#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	CheckHighOrLow(_grade);
	std::cout << "Bureaucrat " << this->_name << " constructor called" << std::endl;
}
Bureaucrat::Bureaucrat() : _name("default"), _grade(2)
{
	CheckHighOrLow(_grade);
	std::cout << "Bureaucrat " << "default" << " constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	CheckHighOrLow(copy._grade);
	std::cout << "Bureaucrat " << this->_name << " copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
		return *this;
	CheckHighOrLow(copy._grade);
	this->_grade = copy._grade;
	std::cout << "Copy Bureaucrat " << this->_name << " Assignment Constructor is Called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Default " << this ->_name << " Bureaucrat destructor called" << std::endl;
}

const std::string Bureaucrat::getName(void) const { return (this->_name);}

int Bureaucrat::getGrade(void) const { return (this->_grade);}

void Bureaucrat::CheckHighOrLow(int grade){
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::increment() {
	try {
		CheckHighOrLow(_grade - 1);
		_grade--;
	} catch (const std::exception &e) {
		std::cout << "Increment failed: " << e.what() << std::endl;
	}
	
}

void Bureaucrat::decrement() {
	try {
		CheckHighOrLow(_grade + 1);
		_grade++;
	} catch (const std::exception &e) {
		std::cout << "Decrement failed: " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
	return (" --- Grade too high ---");
}

const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
	return (" --- Grade too Low ---");
}

void Bureaucrat::signForm(AForm &AForm)
{
	try {
		AForm.beSigned(*this);
		std::cout << _name << " signed AForm " << AForm.getName() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << this->_name << " couldn't sign " << AForm.getName() << 
			" because the lowest grade to sign is " << AForm.getGradeSigned() << "." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const {
    try {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << getName() << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out,  Bureaucrat &Bureaucrat)
{
	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
	return out;
}