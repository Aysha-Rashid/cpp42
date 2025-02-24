#include "PhoneBook.hpp"

int main()
{
	std::string word;
	PhoneBook lst;
	int i = 0;

	while(word != "EXIT" && !std::cin.eof())
	{
		std::cout << "\033[0;34menter your command: \033[0m";
		std::cin >> word;
		if (word == "EXIT" || std::cin.eof())
			break ;
		else if (word == "ADD")
		{
			if (i == 8)
				i = 0;
			lst.Setindex(i);
			if (i < 8)
			{
				if (lst.add() == 1)
					break ;
			}
			i++;
		}
		else if (word == "SEARCH")
			lst.search(word);
		else
			std::cout << "\033[0;31mchoose ADD, SEARCH and EXIT only\033[0m" << std::endl;
	}
}
  