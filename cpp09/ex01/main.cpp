#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw (std::runtime_error("invalid arguments"));
		RPN start(argv[1]);
		start.RPN_calculation();
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}
