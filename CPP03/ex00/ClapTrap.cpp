/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:18:58 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/16 11:30:08 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name("DEFAULT"), _HP(10), _EP(10), _AD(0) {
	std::cout << "ClapTrap " << _name << " criado." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _HP(10), _EP(10), _AD(0) {
	std::cout << "ClapTrap " << _name << " criado." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	*this = other;
	std::cout << "ClapTrap copiado." << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destruído." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount >= _HP)
		_HP = 0;
	else
		_HP -= amount;
	std::cout << "ClapTrap " << _name << " recebeu " << amount << " de dano! HP: " << _HP << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_EP == 0 || _HP == 0) {
		std::cout << "ClapTrap " << _name << " sem energia ou HP para reparar!" << std::endl;
	}
	else {
		_EP--;
		_HP += amount;
		std::cout << "ClapTrap " << _name << " reparado (+" << amount << " HP). HP: " << _HP << " | EP: " << _EP << std::endl;
	}
}

void	ClapTrap::attack(const std::string& target) {
	if (_EP == 0 || _HP == 0) {
		std::cout << "ClapTrap " << _name << " não pode atacar (sem energia ou HP)!" << std::endl;
	}
	else {
		_EP--;
		std::cout << "ClapTrap " << _name << " atacou " << target << " causando " << _AD << " dano! EP: " << _EP << std::endl;
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