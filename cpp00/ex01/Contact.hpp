#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "PhoneBook.hpp"

class Contact
{
	private:
		std::string FirstName;
		std::string LastName;
		std::string NickName;
		std::string	PhoneNumber;
		std::string DarkestSecret;
	public:
		void		SetFirstName(std::string First); // setter
		std::string GetFirstName(); // getter
		void		SetLastName(std::string Last);
		std::string GetLastName();
		int			SetPhoneNumber(std::string Number);
		std::string	GetPhoneNumber();
		void		SetNickName(std::string NickName);
		std::string GetNickName();
		void		SetDarkestSecret(std::string Secret);
		std::string GetDarkestSecret();
};

#endif