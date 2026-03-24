/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:59:21 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/17 13:59:23 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << this->_name << "A zombie has risen..." << std::endl;
};

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << ": was bitten and now is a zombie..." << std::endl;
};

void	Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string _name)
{
	this->_name = _name;
}

Zombie::~Zombie()
{
	std::cout << _name << " died from hunger..." << std::endl;
};