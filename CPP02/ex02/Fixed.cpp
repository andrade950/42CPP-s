/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixec.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:59:16 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/23 14:59:50 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <limits.h>

const int Fixed::_frac_bits = 8;

Fixed::Fixed() : _fixedPoint(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixedPoint(value << _frac_bits) {
	// std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : _fixedPoint(roundf(value * (1 << this->_frac_bits))) {
	// std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

int	Fixed::getRawBits(void) const {
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPoint = raw;
}

// Conversions
int	Fixed ::toInt(void) const {
	return this->_fixedPoint / (1 << this->_frac_bits);
}

float	Fixed ::toFloat(void) const {
	return (static_cast<float>(this->_fixedPoint) / (1 << this->_frac_bits));
}

//Assignment
Fixed& Fixed::operator=(const Fixed &other) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPoint = other.getRawBits();
	return (*this);
}

//Comparison
bool Fixed::operator>(const Fixed &other) const {
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const {
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const {
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const {
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const {
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const {
	return (this->getRawBits() != other.getRawBits());
}

// Calculation
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed res;
	res.setRawBits(this->getRawBits() + other.getRawBits());
	return (res);
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed res;
	res.setRawBits(this->getRawBits() - other.getRawBits());
	return (res);
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed res;
	res.setRawBits((this->getRawBits()  * other.getRawBits()) >> this->_frac_bits);
	return (res);
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed res;
	res.setRawBits((this->getRawBits() << this->_frac_bits)  / other.getRawBits());
	return (res);
}

//PostFix
Fixed	Fixed::operator++(int) {
	Fixed temp(*this);
	this->_fixedPoint++;
	return temp;
}

Fixed	Fixed::operator--(int) {
	Fixed temp(*this);
	this->_fixedPoint--;
	return temp;
}

//Prefix
Fixed&	Fixed::operator++(void) {
	this->_fixedPoint++;
	return *this;
}

Fixed&	Fixed::operator--(void) {
	this->_fixedPoint--;
	return *this;
}

const Fixed&	Fixed::min(const Fixed& lhs, const Fixed& rhs) {
	return (lhs < rhs)? lhs : rhs;
}

Fixed&	Fixed::min( Fixed& lhs,  Fixed& rhs) {
	return (lhs < rhs)? lhs : rhs;
}

const Fixed&	Fixed::max(const Fixed& lhs, const Fixed& rhs) {
	return (lhs > rhs)? lhs : rhs;
}

Fixed&	Fixed::max( Fixed& lhs,  Fixed& rhs) {
	return (lhs > rhs)? lhs : rhs;
}

// Printing
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}