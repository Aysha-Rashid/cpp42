#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try {
		Intern someRandomIntern;
		AForm* rrfp;
		AForm* rrfs;
		AForm* rrfr;

		rrfp = someRandomIntern.makeForm("Presidential pardon", "Bender");
		rrfs = someRandomIntern.makeForm("shrubbery creation", "beauty");
		rrfr = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << rrfp <<std::endl;
		delete rrfp;
		delete rrfs;
		delete rrfr;

		Bureaucrat alice("Alice",44);
		Bureaucrat bob("Bob", 5);
		Bureaucrat leen("leen", 5);
		
		PresidentialPardonForm president("Confidential");
		RobotomyRequestForm robotomy("HumanRobo");
		ShrubberyCreationForm creation("newbie");

		president.beSigned(bob);
		bob.executeForm(president);

		robotomy.beSigned(alice);
		alice.executeForm(robotomy);

		creation.beSigned(leen);
		leen.executeForm(creation);
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
