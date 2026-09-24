#ifndef  FIXED_HPP
#define FIXED_HPP
#pragma once
#include <iostream>
#include <cmath>

class Fixed {
private:
	int _fixedPoint;
	static const int _frac_bits;
public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	~Fixed();
	Fixed(const Fixed &other);

	Fixed&	operator=(const Fixed &other);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	Fixed	operator++(int);
	Fixed	operator--(int);
	Fixed&	operator++(void);
	Fixed&	operator--(void);

	static const Fixed& 	min(const Fixed& lhs, const Fixed& rhs);
	static Fixed& 	min(Fixed& lhs, Fixed& rhs);
	static const Fixed&	max(const Fixed& lhs, const Fixed& rhs);
	static Fixed&	max(Fixed& lhs, Fixed& rhs);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif