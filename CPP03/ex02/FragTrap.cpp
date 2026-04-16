/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:10:49 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/16 11:37:06 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("DEFAULT") {
	_HP = 100; _EP = 100; _AD = 30;
	std::cout << "[FragTrap] " << _name << " criado." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_HP = 100; _EP = 100; _AD = 30;
	std::cout << "[FragTrap] " << _name << " criado." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "[FragTrap] Copiado." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "[FragTrap] " << _name << " destruído." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "[FragTrap] " << _name << " pede um High Five! ✋" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}