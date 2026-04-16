/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:19:18 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/16 13:05:25 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	{
		std::string target = "BOT2";
		ClapTrap BOT1("BOT1");
		BOT1.attack(target);
		BOT1.beRepaired(2);
		BOT1.takeDamage(10);
		BOT1.takeDamage(2);
		BOT1.attack("BOT2");
	}
	{
		std::string target = "BOT2";
		ClapTrap BOT1;
		BOT1.attack(target);
		BOT1.beRepaired(2);
		BOT1.takeDamage(10);
		BOT1.takeDamage(2);
		BOT1.attack("BOT2");
	}
}