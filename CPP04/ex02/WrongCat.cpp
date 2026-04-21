/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:19:56 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/14 13:37:57 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	std::cout << "WrongCat created" << std::endl;

}
WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << "WrongCat created with type: " << this->_type << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat died" << std::endl;
}

void	WrongCat::setType(std::string type) {
	this->_type = type;
}

std::string	WrongCat::getType() const {
	return this->_type;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		this->_type = other.getType();
	}
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "Bark Bark!" << std::endl;
}