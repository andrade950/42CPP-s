/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:00:06 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/16 13:07:18 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	{
		std::cout << std::endl << "ClapTrap" << std::endl;
		ClapTrap BOT1("BOT1");
		ClapTrap BOT2("BOT2");
		BOT2.attack("BOT1");
		BOT1.takeDamage(0);
		BOT2.beRepaired(2);
		BOT2.takeDamage(10);
		BOT2.takeDamage(2);
		BOT2.attack("BOT1");
	}
	{
		std::cout << std::endl << "ScavTrap" << std::endl;
		ClapTrap BOT1("BOT1");
		ScavTrap BOT3("BOT3");
		BOT3.attack("BOT1");
		BOT1.takeDamage(20);
		BOT3.beRepaired(2);
		BOT3.takeDamage(10);
		BOT3.takeDamage(2);
		BOT3.attack("BOT1");
		BOT3.guardGate();
	}
	{
		std::cout << std::endl << "pointerrr" << std::endl;
		ClapTrap BOT1("BOT1");
		ClapTrap *BOT4 = new ScavTrap("BOT4");
		BOT4->attack("BOT1");
		BOT4->takeDamage(100);
		delete BOT4;
	}
}
