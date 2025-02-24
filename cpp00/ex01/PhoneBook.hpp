#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contact[8];
		int index;

	public:
		int add();
		void search(std::string word);
		void displayContact(int index);
		void Setindex(int Setindex);
		int GetIndex();
};

#endif