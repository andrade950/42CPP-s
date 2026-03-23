/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:43:00 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/12 10:15:57 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"
#include <iomanip>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

Phonebook::Phonebook()
{
	this->_index = 0;
}

void Phonebook::add(Contact contact)
{
	this->_contacts[_index] = contact;
	this->_index = (this->_index + 1) % 8;
}

std::string Format(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + '.';
	std::ostringstream formatted;
	formatted << std::right << std::setfill(' ') << std::setw(10) << str;
	return (formatted.str());
}

int	SearchUi(Contact contacts[8])
{
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|  Details of contact found                 |" << std::endl;
	std::cout << "|    Index | First_name|Last_name| Nickname | " << std::endl;
	std::cout << "|----------|----------|----------|----------| " << std::endl;
	if (contacts[0].get_first_name().length() == 0)
	{
		std::cout << "|  No contacts found...                     |" << std::endl;
		std::cout << "|___________________________________________|" << std::endl;
		return (0);
	}
	for (int i = 0; i < 8 && contacts[i].get_first_name().length() != 0; i++)
	{
		std::cout << "|" << std::setw(10) << i
			<< "|" << Format(contacts[i].get_first_name())
			<< "|" << Format(contacts[i].get_last_name())
			<< "|" << Format(contacts[i].get_nickname()) << "|"<< std::endl;
		if (i + 1 < 8 && contacts[i + 1].get_first_name().length() != 0)
			std::cout <<"|-------------------------------------------| " << std::endl;
		else
			std::cout <<"|___________________________________________| " << std::endl;
	}
	return (1);
}

void Phonebook::search()
{
	std::string temp;

	if (!SearchUi(this->_contacts))
		return ;
	GetPrompt("Search [0 .. 7]: ", temp);
	if (IsNumber(temp) == 1 && Stoi(temp) < 8 && Stoi(temp) >= 0)
		std::cout << "Searching ..." << std::endl;
	else
	{
		std::cout << "Invalid Index, choose between 0 and 7" << std::endl;
		return ;
	}
	int index = Stoi(temp);
	std::cout << " ___________________________________________  " << std::endl;
	std::cout << "|  Details of contact found                 | " << std::endl;
	std::cout << "|___________________________________________| " << std::endl;
	if (this->_contacts[index].get_first_name().length() == 0)
	{
		std::cout << "|  No contacts found in the index...        |" << std::endl;
		std::cout << "|___________________________________________|" << std::endl;
		return ;
	}
	std::cout << "First name: " << this->_contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << this->_contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number: " << this->_contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << this->_contacts[index].get_darkest_secret() << std::endl;
	std::cout << std::endl <<std::endl;
}

Contact Phonebook::get_contact(int index)
{
	return (this->_contacts[index]);
}