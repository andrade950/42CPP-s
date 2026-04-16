/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:10:34 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/16 11:37:22 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("DEFAULT"), _HP(10), _EP(10), _AD(0) {
	std::cout << "[ClapTrap] " << _name << " criado." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HP(10), _EP(10), _AD(0) {
	std::cout << "[ClapTrap] " << _name << " criado." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	std::cout << "[ClapTrap] Copiado." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "[ClapTrap] " << _name << " destruído." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_EP == 0 || _HP == 0)
		std::cout << "[ClapTrap] " << _name << " sem energia/vida!" << std::endl;
	else {
		_EP--;
		std::cout << "[ClapTrap] " << _name << " ataca " << target << ". EP: " << _EP << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= _HP) _HP = 0;
	else _HP -= amount;
	std::cout << "[ClapTrap] " << _name << " dano: " << amount << ". HP: " << _HP << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_EP == 0 || _HP == 0)
		std::cout << "[ClapTrap] " << _name << " sem energia!" << std::endl;
	else {
		_EP--;
		_HP += amount;
		std::cout << "[ClapTrap] " << _name << " reparado. HP: " << _HP << std::endl;
	}
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_HP = other._HP;
		this->_EP = other._EP;
		this->_AD = other._AD;
	}
	return (*this);
}