/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:42:51 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/11 13:59:36 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iomanip>

bool	GetPrompt(std::string msg, std::string &var)
{
	std::cout << msg;
	std::getline(std::cin, var);
	if (std::cin.eof() || std::cin.fail() )
	{
		std::cout << std::endl <<"You pressed Ctrl + D, Program is Quitting" << std::endl;
		return false;
	}
	std::cout << std::endl;
	return true;
}

Contact	CreateContact()
{
	Contact temp;
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phone;
	std::string secret;
	std::cout << "Please enter contact details : "<< std::endl;
	GetPrompt("First Name : ", firstname);
	if (firstname.length() == 0)
		return temp;
	GetPrompt("Last Name : ", lastname);
	if (lastname.length() == 0)
		return temp;
	GetPrompt("NickName : ", nickname);
	if (nickname.length() == 0)
		return temp;
	while (GetPrompt("Phone Number : ", phone) && ((IsNumber(phone) == 0 || phone.length() != 9))) {
		std::cout << "Phone number not valid. Must have 9 digits"<< std::endl;
		sleep(1);
		std::cout << "Please try again."<< std::endl;
		sleep(1);
	}
	if (phone.length() == 0)
		return temp;
	GetPrompt("Darkest Secret : ", secret);
	if (secret.length() == 0)
		return temp;
	temp.set_first_name(firstname);
	temp.set_last_name(lastname);
	temp.set_phone_number(phone);
	temp.set_nickname(nickname);
	temp.set_darkest_secret(secret);
	return (temp);
}

int	main()
{
	Phonebook phonebook;

	HandleSignal();
	std::cout << "\033[2J\033[H";
	std::string input;
	do
	{
		Display();
		if (!GetPrompt("Type your option : ", input))
			break;
		if (std::cin.fail()){
			std::cout << "Invalid input. Please enter ADD, SEARCH or EXIT" << std::endl, sleep(1);
			continue;
		}
		else if (input == "ADD")
		{
			Contact temp;
			temp = CreateContact();
			if (!std::cin.eof() && temp.get_first_name().length() == 0) {
				std::cout << "All contact field must be filled" << std::endl;
				continue;
			}
			phonebook.add(temp);
		}
		else if (input == "SEARCH")
			phonebook.search();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Invalid input." << std::endl, sleep(1);
	} while (input != "EXIT" && !std::cin.eof());
	std::cout << "Exiting.. Thank you!" << std::endl;
	return (0);
}