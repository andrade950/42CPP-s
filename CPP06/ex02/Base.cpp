/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:51:59 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/13 12:52:05 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base(){}

Base*	generate(void) {
	int rand = std::rand() % 3;
	switch (rand) {
		case 0 : return new A();
		case 1 : return new B();
		case 2 : return new C();
	}
	return NULL;
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Class is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class is C" << std::endl;
	else
		std::cout << "Class not identifiable" << std::endl;
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "Class is A" << std::endl;
		return ;
		}
	catch (std::exception &e) { }
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "Class is B" << std::endl;
		return ;
		}
	catch (std::exception &e) { }
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "Class is C" << std::endl;
		return ;
		}
	catch (std::exception &e) { }
	std::cout << "Class not identifiable" << std::endl;
}