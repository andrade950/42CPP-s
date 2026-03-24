/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:17:03 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/17 14:17:11 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
	private:
	std::string _name;
	Weapon& _weapon;
	public:
	void	attack();
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
};