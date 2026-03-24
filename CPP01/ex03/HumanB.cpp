/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:17:21 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/17 14:17:28 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack(){
	if (this->_weapon == NULL || this->_weapon->getType().length() == 0) {

		std::cout << this->_name << " attacks with their hands" << std::endl;
	}
	else {
		std::cout << this->_name << " attacks with their "
			<< this->_weapon->getType() << std::endl;
	}
}

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

HumanB::~HumanB() {};