/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SetterGetter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:24:30 by ayal-ras          #+#    #+#             */
/*   Updated: 2024/07/09 20:13:23 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//-------------Getter-------------
std::string Contact::GetFirstName()
{
	return FirstName;
}

std::string Contact::GetLastName()
{
	return LastName;
}

std::string Contact::GetDarkestSecret()
{
	return DarkestSecret;
}

std::string Contact::GetNickName()
{
	return NickName;
}

std::string Contact::GetPhoneNumber()
{
	return PhoneNumber;
}

int 	PhoneBook::GetIndex()
{
	return (index);
}

//-------------------Setter--------------------
void	Contact::SetFirstName(std::string First)
{
	FirstName = First;
}

void	Contact::SetLastName(std::string Last)
{
	LastName = Last;
}

void	Contact::SetDarkestSecret(std::string Secret)
{
	DarkestSecret = Secret;
}

void	Contact::SetNickName(std::string Nick)
{
	NickName = Nick;
}

int	Contact::SetPhoneNumber(std::string Number)
{
	int i = 0;
	while (Number[i])
	{
		if (Number[i] >= '0' && Number[i] <= '9')
			PhoneNumber = Number;
		else
			return (0);
		i++;
	}
	return (1);
}

void	PhoneBook::Setindex(int Setindex)
{
	index = Setindex;
}
