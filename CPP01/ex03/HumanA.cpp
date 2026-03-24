/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:16:57 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/17 14:17:01 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack(){
	std::cout << this->_name << " attacks with their "
	<< this->_weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {} ;
HumanA::~HumanA() {};