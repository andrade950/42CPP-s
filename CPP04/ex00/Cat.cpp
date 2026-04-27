/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:03:52 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/27 13:47:52 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "Cat created" << std::endl;

}
Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Cat created with type: " << this->_type << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	*this = other;
}

Cat::~Cat() {
	std::cout << "Cat died" << std::endl;
}

void	Cat::setType(std::string type) {
	this->_type = type;
}

std::string	Cat::getType() const {
	return this->_type;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow!" << std::endl;
}