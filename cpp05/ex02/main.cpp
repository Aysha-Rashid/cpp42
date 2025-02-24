#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	try {
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
