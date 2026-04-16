/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:28:25 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/16 11:37:13 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("DEFAULT"), _gateMode(false) {
	_HP = 100; _EP = 50; _AD = 20;
	std::cout << "[ScavTrap] " << _name << " criado." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _gateMode(false) {
	_HP = 100; _EP = 50; _AD = 20;
	std::cout << "[ScavTrap] " << _name << " criado." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "[ScavTrap] Copiado." << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "[ScavTrap] " << _name << " destruído." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_EP == 0 || _HP == 0)
		std::cout << "[ScavTrap] " << _name << " sem energia/vida!" << std::endl;
	else {
		_EP--;
		std::cout << "[ScavTrap] " << _name << " ataca " << target << ". EP: " << _EP << std::endl;
	}
}

void ScavTrap::guardGate(void) {
	this->_gateMode = true;
	std::cout << "[ScavTrap] " << _name << " em modo Gatekeeper." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		this->_gateMode = other._gateMode;
	}
	return (*this);
}