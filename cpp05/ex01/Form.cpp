#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, const int signedGrade, const int executeGrade) : _name(name), _gradeSigned(signedGrade), _gradeExecute(executeGrade), _signed(0)
{
	check(*this);
	std::cout << "Form " << name << " constructor called" << std::endl;
}
Form::Form() : _name("default"), _gradeSigned(2), _gradeExecute(2), _signed(0)
{
	check(*this);
	std::cout << "Form " << "default" << " constructor called" << std::endl;
}
Form::Form(Form &copy) : _name(copy._name), _gradeSigned(copy._gradeSigned), _gradeExecute(copy._gradeExecute), _signed(copy._signed)
{
	check(copy);
	std::cout << "Form " << this->_name << " Copy Constuctor is being called" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
	check(copy);
	if (this == &copy)
		return *this;
	const_cast<std::string&>(this->_name) = copy._name;
	const_cast<int&>(this->_gradeSigned) = copy._gradeSigned;
	const_cast<int&>(this->_gradeExecute) = copy._gradeExecute;
	this->_signed = copy._signed;
	std::cout << "Copy Form Assignment Constructor is Called" << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Default " << this->_name << " Form destructor called" << std::endl;
}
void Form::check(const Form &copy)
{
	if (copy._gradeSigned > 150)
		throw Form::GradeTooLowException();
	else if (copy._gradeSigned < 1)
		throw Form::GradeTooHighException();
	if (copy._gradeExecute < 1)
		throw Form::GradeTooHighException();
	else if (copy._gradeExecute > 150)
		throw Form::GradeTooLowException();
}

std::string Form::getName() const{ return(this->_name); }
int Form::getGradeSigned() const{ return(this->_gradeSigned); }
int Form::getExecute() const{ return(this->_gradeExecute); }
bool Form::getSigned() { return(this->_signed); }

void Form::beSigned(Bureaucrat Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->_gradeSigned)
		throw GradeTooLowException();
	this->_signed = 1;
	std::cout << Bureaucrat.getName() << " successfully signed " << this->_name << std::endl;
}

const char* Form::GradeTooHighException::what() const throw ()
{
	return (" --- Grade too high to sign this form ---");
}

const char* Form::GradeTooLowException::what() const throw ()
{
	return (" --- Grade too Low to sign this form ---");
}

const char* Form::GradeNotSigned::what() const throw ()
{
	return (" --- Form not signed ---");
}


std::ostream &operator<<(std::ostream &out,  Form &Form)
{
	out << Form.getName() << ", needs to have sign grade:  " << Form.getGradeSigned() << 
		 " to sign the form and have the execute grade: " 
		<< Form.getExecute()  << " to execute the form " << std::endl;
	return out;
}
