/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:58:57 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/23 14:58:59 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
	{
		// Subject main

		std::cout << "Subject Main" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	{
		std::cout << "Comparison Main" << std::endl;
		Fixed a;
		Fixed const b( 8388608 );
		Fixed const c( 1 );
		Fixed const d( b );
		a = Fixed( 1 );
		Fixed const e( 10 );

		std::cout << std::endl;
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;
		std::cout << "c is " << c << std::endl;
		std::cout << "d is " << d << std::endl;
		std::cout << std::endl;
		std::cout << "a (" << a << ") is bigger than b (" << b <<") ? -> " << (a > b) << std::endl;
		std::cout << "c (" << c << ") is bigger than b (" << b <<") ? -> " << (c > b) << std::endl;
		std::cout << std::endl;
		std::cout << "c (" << c << ") is bigger or equal than b (" << b <<") ? -> " << (c >= b) << std::endl;
		std::cout << "e (" << e << ") is bigger or equal than b (" << b <<") ? -> " << (e >= b) << std::endl;
		std::cout << "a (" << a << ") is bigger or equal than b (" << b <<") ? -> " << (a >= b) << std::endl;
		std::cout << std::endl;
		std::cout << "c (" << c << ") is less or equal than b (" << b <<") ? -> " << (c <= b) << std::endl;
		std::cout << "e (" << e << ") is less or equal than b (" << b <<") ? -> " << (e <= b) << std::endl;
		std::cout << "a (" << a << ") is less or equal than b (" << b <<") ? -> " << (a <= b) << std::endl;
		std::cout << std::endl;
		std::cout << "c (" << c << ") is  equal than b (" << b <<") ? -> " << (c == b) << std::endl;
		std::cout << "e (" << e << ") is  equal than b (" << b <<") ? -> " << (e == b) << std::endl;
		std::cout << "a (" << a << ") is  equal than b (" << b <<") ? -> " << (a == b) << std::endl;
		std::cout << std::endl;
		std::cout << "c (" << c << ") is not equal than b (" << b <<") ? -> " << (c != b) << std::endl;
		std::cout << "e (" << e << ") is not equal than b (" << b <<") ? -> " << (e != b) << std::endl;
		std::cout << "a (" << a << ") is not equal than b (" << b <<") ? -> " << (a != b) << std::endl;
		std::cout << std::endl;
		std::cout << "a is " << a.toInt() << " as integer" << std::endl;
		std::cout << "b is " << b.toInt() << " as integer" << std::endl;
		std::cout << "c is " << c.toInt() << " as integer" << std::endl;
		std::cout << "d is " << d.toInt() << " as integer" << std::endl;
		std::cout << "e is " << e.toInt() << " as integer" << std::endl;
	}
	{
		std::cout << "Calculation Main" << std::endl;
		Fixed const a( 42.42f );
		Fixed const b( 10 );

		std::cout << std::endl;
		std::cout << "a is " << a << std::endl;
		std::cout << "b is " << b << std::endl;

		std::cout << "a (" << a << ") + b (" << b <<") ? -> " << (a + b) << std::endl;
		std::cout << "a (" << a << ") - b (" << b <<") ? -> " << (a - b) << std::endl;
		std::cout << "a (" << a << ") * b (" << b <<") ? -> " << (a * b) << std::endl;
		std::cout << "a (" << a << ") / b (" << b <<") ? -> " << (a / b) << std::endl;
	}
	{
		std::cout << "Increment Main" << std::endl;
		Fixed a( 10 );
		Fixed b( 42.42f );

		std::cout << std::endl;

		std::cout << "a (" << a << ") 'during post' increment (" << a++  << ") after increment (" << a++ << ")" << std::endl;
		std::cout << "b (" << b << ") 'during post' increment (" << b++  << ") after increment (" << b++ << ")" << std::endl;
		std::cout << "a (" << a << ") 'during pre' increment (" << ++a  << ") after increment (" << a++ << ")" << std::endl;
		std::cout << "b (" << b << ") 'during pre' increment (" << ++b  << ") after increment (" << b++ << ")" << std::endl;
		std::cout << std::endl;

		std::cout << "a (" << a << ") 'during post' decrement (" << a--  << ") after decrement (" << a-- << ")" << std::endl;
		std::cout << "b (" << b << ") 'during post' decrement (" << b--  << ") after decrement (" << b-- << ")" << std::endl;
		std::cout << "a (" << a << ") 'during pre' decrement (" << --a  << ") after decrement (" << a-- << ")" << std::endl;
		std::cout << "b (" << b << ") 'during pre' decrement (" << --b  << ") after decrement (" << b-- << ")" << std::endl;
	}
	{
		std::cout << "Min/max Main" << std::endl;
		Fixed a( 10 );
		Fixed b( 42.42f );
		const Fixed c( 1.0f );
		const Fixed d( 2.42f );

		std::cout << std::endl;

		std::cout << "a (" << ++a << ") or b(" << ++b  << ") is min (" << Fixed::min(a, b) << ")" << std::endl;
		std::cout << "a (" << ++a << ") or b(" <<++ b  << ") is max (" << Fixed::max(a, b) << ")" << std::endl;
		std::cout << "a (" << a << ") or a(" << a  << ") is max (" << Fixed::max(a, a) << ")" << std::endl;
		std::cout << "c (" << c << ") or d(" << d  << ") is min (" << Fixed::min(c, d) << ")" << std::endl;
		std::cout << "c (" << c << ") or d(" << d  << ") is max (" << Fixed::max(c, d) << ")" << std::endl;
	}
}