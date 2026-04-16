/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:28:43 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/13 14:28:45 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
	}
	{
		std::cout << std::endl << "ScavTrap" << std::endl;
		std::string target = "Sandro";
		ClapTrap *Tome = new ScavTrap("Tome");
		Tome->attack(target);
		Tome->takeDamage(100);
		delete Tome;
	}
	{
		std::string target = "Ambrosio";
		std::cout << std::endl << "FragTrap" << std::endl;
		FragTrap *Tome = new FragTrap("Tome");
		Tome->attack(target);
		Tome->takeDamage(100);
		Tome->highFivesGuys();
		Tome->highFivesGuys();
		Tome->highFivesGuys();
		Tome->highFivesGuys();
		delete Tome;
	}
	{
		FragTrap Faby("Faby");
		FragTrap Chone(Faby);

		Faby.attack("Target");
		Faby.takeDamage(50);
		Faby.beRepaired(20);
		Faby.highFivesGuys();

		FragTrap Orlando("Another");
		Orlando = Faby;
	}
}