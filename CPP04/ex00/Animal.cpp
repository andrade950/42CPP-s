/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:56:51 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/13 14:57:31 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("No Species"){
	std::cout << "Animal created" << std::endl;

}
Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal created with type: " << this->_type << std::endl;
}

Animal::Animal(const Animal& other) {
	*this = other;
}

Animal::~Animal() {
	std::cout << "Animal died" << std::endl;
}

void	Animal::setType(std::string type) {
	this->_type = type;
}

std::string	Animal::getType() const {
	return this->_type;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

void	Animal::makeSound() const {
	std::cout << "No Species No sound!" << std::endl;
}