/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:00:17 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/16 11:56:41 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap("DEFAULT") {
    _HP = 100; _EP = 50; _AD = 20; _gateMode = false;
    std::cout << "[ScavTrap] " << _name << " inicializado." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    _HP = 100; _EP = 50; _AD = 20; _gateMode = false;
    std::cout << "[ScavTrap] " << _name << " inicializado." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    *this = other;
}

ScavTrap::~ScavTrap() {
    std::cout << "[ScavTrap] " << _name << " removido." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (_EP == 0 || _HP == 0) {
        std::cout << "[ScavTrap] " << _name << " incapaz de atacar." << std::endl;
    } else {
        _EP--;
        std::cout << "[ScavTrap] " << _name << " investiu contra " << target << " (" << _AD << " dano). EP: " << _EP << std::endl;
    }
}

void ScavTrap::guardGate(void) {
    _gateMode = true;
    std::cout << "[ScavTrap] " << _name << " entrou em modo Gatekeeper." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
        this->_gateMode = other._gateMode;
    }
    return (*this);
}