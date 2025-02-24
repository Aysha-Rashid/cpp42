#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat alice("Alice", 2);
		Bureaucrat bob("Bob", 6);
		Form form("Confidential", 3, 5); 

		alice.signForm(form);
		std::cout << form;

		bob.signForm(form);

		bob = alice; // wont even bother to come here after it caught the exception
		bob.signForm(form);
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
