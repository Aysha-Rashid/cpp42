#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(Intern &copy)
{
    *this = copy;
	std::cout << "Copy Intern Constuctor is being called" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
	std::cout << "Copy Intern Assignment Constructor is Called" << std::endl;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Default Intern destructor called" << std::endl;
}
static AForm *PresidentialForm(const std::string target)
{
    AForm *president = new PresidentialPardonForm(target);
    std::cout << "Intern creates " << target << " PresidentialForm" << std::endl;
	return (president);
}
static AForm *ShrubberyForm(const std::string target)
{
    AForm *tree = new ShrubberyCreationForm(target);
    std::cout << "Intern creates " << target << " ShrubberyForm" << std::endl;
	return (tree);
}
static AForm *RobotomyForm(const std::string target)
{
    AForm *robo = new RobotomyRequestForm(target);
    std::cout << "Intern creates " << target << " RobotomyForm" << std::endl;
	return (robo);
}

const char* Intern::NoFormFound::what() const throw ()
{
	return (" --- No such form is found ---");
}

AForm *Intern::makeForm(std::string form, std::string target)   
{
    AForm *returnValue = NULL;
    const std::string input[4] = {"presidential pardon", "shrubbery creation", "robotomy request"};
    AForm *(*func[4])(std::string target) = {&PresidentialForm, &ShrubberyForm, &RobotomyForm};

    for (size_t i = 0; i < form.length(); i++)
        form[i] = tolower(form[i]);
    for (size_t cur = 0; cur < (sizeof(input) / sizeof(input[0])); cur++)
    {
        if (form == input[cur])
        {
            returnValue = func[cur](target);
            break;
        }
    }
    if (returnValue == NULL)
        throw NoFormFound();
    return (returnValue);
}

std::ostream &operator<<(std::ostream &out,  Intern &Intern)
{
    (void)Intern;
	out << "Intern needs to create a form for specified Bureaucrat" << std::endl;
	return out;
}