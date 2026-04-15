/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:57:05 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/23 14:57:06 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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