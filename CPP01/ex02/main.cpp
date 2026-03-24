/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:06:47 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/17 14:06:49 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	std::cout << "Address of string : " << &string << std::endl;
	std::cout << "Address of stringPTR : " << stringPTR << std::endl;
	std::cout << "Address of stringREF : " << &stringREF << std::endl<< std::endl;
	std::cout << "The value of string : " << string << std::endl;
	std::cout << "The value pointed to stringPTR : " << *stringPTR << std::endl;
	std::cout << "The value pointed to stringREF : " << stringREF << std::endl;
}