/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:19:18 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/16 11:31:15 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	{
		std::string target = "Sandro";
		ClapTrap Joel("Joel");
		Joel.attack(target);
		Joel.beRepaired(2);
		Joel.takeDamage(10);
		Joel.takeDamage(2);
		Joel.attack("Sandro");
	}
	{
		std::string target = "Sandro";
		ClapTrap Joel;
		Joel.attack(target);
		Joel.beRepaired(2);
		Joel.takeDamage(10);
		Joel.takeDamage(2);
		Joel.attack("Sandro");
	}
}