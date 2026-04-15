/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:57:15 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/23 14:57:16 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_frac_bits = 8;

Fixed::Fixed() : _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const int value) : _fixedPoint(value << _frac_bits) {
	std::cout << "Int constructor called" << std::endl;

}

Fixed::Fixed(const float value) : _fixedPoint(roundf(value * (1 << this->_frac_bits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPoint = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPoint = raw;
}

int	Fixed ::toInt(void) const {
	return this->_fixedPoint / (1 << this->_frac_bits);
}

float	Fixed ::toFloat(void) const {
	return (static_cast<float>(this->_fixedPoint) / (1 << this->_frac_bits));
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}