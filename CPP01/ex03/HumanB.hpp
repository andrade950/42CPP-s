/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:17:46 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/17 14:17:54 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"
#include <iostream>

class HumanB {
	private:
	std::string _name;
	Weapon *_weapon;
	public:
	void	attack();
	HumanB(std::string);
	void	setWeapon(Weapon& weapon);
	~HumanB();
};