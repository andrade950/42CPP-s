/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:00:06 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/13 14:00:07 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	{
		std::cout << std::endl << "ClapTrap" << std::endl;
		std::string target = "Sandro";
		ClapTrap Joel("Joel");
		Joel.attack(target);
		Joel.beRepaired(2);
		Joel.takeDamage(10);
		Joel.takeDamage(2);
		Joel.attack("Sandro");
	}
	{
		std::cout << std::endl << "ScavTrap" << std::endl;
		std::string target = "Sandro";
		ScavTrap Tony("Tony");
		Tony.attack(target);
		Tony.beRepaired(2);
		Tony.takeDamage(10);
		Tony.takeDamage(2);
		Tony.attack("Sandro");
		Tony.guardGate();
	}
	{
		std::string target = "Sandro";
		std::cout << std::endl << "pointerrr" << std::endl;
		ClapTrap *Tome = new ScavTrap("Tome");
		Tome->attack(target);
		Tome->takeDamage(100);
		delete Tome;
	}
}