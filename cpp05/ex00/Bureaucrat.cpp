#include "Bureaucrat.hpp"

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

const std::string Bureaucrat::getName(void) { return (this->_name);}

int Bureaucrat::getGrade(void) { return (this->_grade);}

void Bureaucrat::CheckHighOrLow(int grade){
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
}


void Bureaucrat::increment() {
        CheckHighOrLow(_grade - 1);
        _grade--;
}

void Bureaucrat::decrement() {
    CheckHighOrLow(_grade + 1);
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw ()
{
    return (" --- Grade too high ---");
}

const char* Bureaucrat::GradeTooLowException::what() const throw ()
{
    return (" --- Grade too Low ---");
}

std::ostream &operator<<(std::ostream &out,  Bureaucrat &Bureaucrat)
{
    out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
    return out;
}