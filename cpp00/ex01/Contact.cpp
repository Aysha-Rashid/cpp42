#include "PhoneBook.hpp"
#include <stdio.h>

int valid_phone(void)
{
	std::string	PhoneNumber;
	Contact		list;

	std::cout << "Enter the PhoneNumber: " << std::flush;
	std::getline(std::cin >> std::ws, PhoneNumber);
	if (PhoneNumber == "EXIT")
		return (2);
	if (list.SetPhoneNumber(PhoneNumber))
		std::cout << "\033[0;35mPhone Number set to: \033[0m" << list.GetPhoneNumber() << std::endl;
	else
		return (std::cout << "Invalid phone number. Please enter digits only." << std::endl, 0);
	return (1);
}
int	PhoneBook::add()
{
	Contact		list;
	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	DarkestSecret;
	std::string	PhoneNumber;

	std::cout << "Enter the First name: " << std::flush;
	std::getline(std::cin >> std::ws, FirstName);
	if (std::cin.eof() || FirstName == "EXIT")
		return (1);
	list.SetFirstName(FirstName);
	std::cout << "\033[0;35mFirst Name set to: \033[0m" << list.GetFirstName() << std::endl;

	std::cout << "Enter the Last name: " << std::flush;
	std::getline(std::cin >> std::ws, LastName);
	if (std::cin.eof() || LastName == "EXIT")
		return (1);
	list.SetLastName(LastName);
	std::cout << "\033[0;35mLast Name set to: \033[0m" << list.GetLastName() << std::endl;

	std::cout << "Enter the Nickname: " << std::flush;
	std::getline(std::cin >> std::ws, NickName);
	if (std::cin.eof() || NickName == "EXIT")
		return (1);
	list.SetNickName(NickName);
	std::cout << "\033[0;35mNickName set to: \033[0m" << list.GetNickName() << std::endl;
	int ret_value = 0;
	while (1)
	{
		ret_value = valid_phone();
		if (ret_value == 1)
			break ;
		else if (ret_value == 2)
			return (1);
	}
	std::cout << "Enter the DarkestSecret: " << std::flush;
	std::getline(std::cin >> std::ws, DarkestSecret);
	if (std::cin.eof() || DarkestSecret == "EXIT")
		return (1);
	list.SetDarkestSecret(DarkestSecret);
	std::cout << "\033[0;35mDarkestSecret set to: \033[0m" << list.GetDarkestSecret() << std::endl;
	contact[index] = list;
	index = (index + 1) % 8;
	return (0);
}

std::string formatText(const std::string& text, int width)
{
	std::string formattedText;
	if (text.size() >= static_cast<std::string::size_type>(width))
		formattedText = text.substr(0, width - 1) + ".";
	else
		formattedText = std::string(width - text.size(), ' ') + text;
	return formattedText;
}

void PhoneBook::displayContact(int index)
{
	std::cout << std::setw(11) << "Index" << "|"
	<< formatText("FirstName", 11) << "|"
	<< formatText("LastName", 11) << "|"
	<< formatText("NickName", 11) << std::endl;
	if (contact[index].GetFirstName().empty())
		std::cout << std::setw(11) << "" << "|";
	else
		std::cout << std::setw(11) << index << "|";
	std::cout << formatText(contact[index].GetFirstName(), 11) << "|"
	<< formatText(contact[index].GetLastName(), 11) << "|"
	<< formatText(contact[index].GetNickName(), 11) << std::endl;
}

void	PhoneBook::search(std::string word)
{
	int i = -1;
	int index = 0;
	PhoneBook check;

	i = -1;
	std::cout << "Enter the index of the contact you want to view: ";
	std::cin >> word;
	while (word[++i])
	{
		if (std::cin.eof() || word == "EXIT")
			return ;
		if (!isdigit(word[i]))
		{
			std::cout << "\033[0;31mShould be the index value\033[0;0m" << std::endl;
			return ;
		}
		if (word[i] < '0' || word[i] > '7')
		{
			std::cout << "\033[0;31mShould be within 0 to 7 index\033[0;0m" << std::endl;
			return ;
		}
	}
	index = atoi(word.c_str());
	displayContact(index);
}
