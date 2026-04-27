/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:15:51 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/27 13:50:42 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("No Species"){
	std::cout << "WrongAnimal created" << std::endl;

}
WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal created with type: " << this->_type << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal died" << std::endl;
}

void	WrongAnimal::setType(std::string type) {
	this->_type = type;
}

std::string	WrongAnimal::getType() const {
	return this->_type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal No Species No sound!" << std::endl;
}