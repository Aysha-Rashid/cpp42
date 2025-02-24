#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : AForm(name, 25, 5) , _target(name)
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy) : AForm("ShrubberyCreationForm", 25, 5)
{
	this->_target = copy._target;
	std::cout << "Copy ShrubberyCreationForm Constuctor is being called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	std::cout << "Copy ShrubberyCreationForm Assignment Constructor is Called" << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Default ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getSigned())
        throw AForm::GradeNotSigned();
    else if (executor.getGrade() > getExecute())
        throw GradeTooLowException();

    // Write shrubbery ASCII art to a file
    std::ofstream outFile((_target + "_shrubbery").c_str());
    if (!outFile)
        throw std::ios_base::failure("Failed to open file.");

    outFile << "       _-_\n"
            << "    /~~   ~~\\\n"
            << " /~~         ~~\\\n"
            << "{               }\n"
            << " \\  _-     -_  /\n"
            << "   ~  \\\\ //  ~\n"
            << "_- -   | | _- _\n"
            << "  _ -  | |   -_\n"
            << "      // \\\\\n";

    outFile.close();
    std::cout << "Shrubbery has been planted in " << _target + "_shrubbery" << std::endl;
}


std::ostream &operator<<(std::ostream &out,  ShrubberyCreationForm &ShrubberyCreationForm)
{
	out << ShrubberyCreationForm.getName() << ", needs to have sign grade:  " << 
        ShrubberyCreationForm.getGradeSigned() << 
		 " to sign the ShrubberyCreationForm and have the execute grade: " 
		<< ShrubberyCreationForm.getExecute()  << " to execute the ShrubberyCreationForm " << std::endl;
	return out;
}
