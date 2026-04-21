/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:03:52 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/13 16:21:26 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : brain(new(Brain)) {
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(), brain(new Brain(*other.brain)) {
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
		_type = other._type;
	}
	return (*this);
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat died" << std::endl;
}

void	Cat::setType(std::string type) {
	this->_type = type;
}

std::string	Cat::getType() const {
	return this->_type;
}

void	Cat::makeSound() const {
	std::cout << "Meow Meow!" << std::endl;
}

std::string	Cat::getIdea(unsigned int index) {
	if (index < 1 || index < 100) {
		std::cout << "Index must be between 1 an 100" << std::endl;
		return "";
	}
	else
		return this->brain->ideas[index - 1];
}

void	Cat::setIdea(unsigned int index, std::string idea) {
	if (index < 1 || index < 100) {
		std::cout << "Index must be between 1 an 100" << std::endl;
	}
	else
		this->brain->ideas[index - 1] = idea;
}