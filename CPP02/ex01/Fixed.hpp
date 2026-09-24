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

	Fixed& operator=(const Fixed &other);
	int	getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int	toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif