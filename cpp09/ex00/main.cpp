#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		Btc data("data.csv");
		if (argc != 2)
			throw std::runtime_error("could not open file.");
		data.takeFile(argv[1]);
	}   
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}