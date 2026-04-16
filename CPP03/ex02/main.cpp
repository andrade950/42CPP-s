/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:28:43 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/16 13:07:04 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	{
		std::cout << std::endl << "ClapTrap" << std::endl;
		std::string target = "BOT2";
		ClapTrap BOT1("BOT1");
		BOT1.attack(target);
		BOT1.beRepaired(2);
		BOT1.takeDamage(10);
		BOT1.takeDamage(2);
		BOT1.attack("BOT2");
	}
	{
		std::cout << std::endl << "ScavTrap" << std::endl;
		std::string target = "BOT2";
		ScavTrap BOT3("BOT3");
		BOT3.attack(target);
		BOT3.beRepaired(2);
		BOT3.takeDamage(10);
		BOT3.takeDamage(2);
		BOT3.attack("BOT2");
	}
	{
		std::cout << std::endl << "ScavTrap" << std::endl;
		std::string target = "BOT2";
		ClapTrap *BOT4 = new ScavTrap("BOT4");
		BOT4->attack(target);
		BOT4->takeDamage(100);
		delete BOT4;
	}
	{
		std::string target = "BOT5";
		std::cout << std::endl << "FragTrap" << std::endl;
		FragTrap *BOT4 = new FragTrap("BOT4");
		BOT4->attack(target);
		BOT4->takeDamage(100);
		BOT4->highFivesGuys();
		BOT4->highFivesGuys();
		BOT4->highFivesGuys();
		BOT4->highFivesGuys();
		delete BOT4;
	}
	{
		FragTrap BOT6("BOT6");
		FragTrap Chone(BOT6);

		BOT6.attack("Target");
		BOT6.takeDamage(50);
		BOT6.beRepaired(20);
		BOT6.highFivesGuys();

		FragTrap BOT7("Another");
		BOT7 = BOT6;
	}
}