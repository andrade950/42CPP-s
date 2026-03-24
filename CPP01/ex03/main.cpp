/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:17:56 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/17 14:26:53 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	{
		std::string wp = "crude spliked club";
		Weapon club = Weapon(wp);
		HumanB joel("Joel");
		joel.attack();
		joel.setWeapon(club);
		club.setType("some other type of club");
		joel.attack();
	}
	{
		std::string wp = "";
		Weapon club = Weapon(wp);
		HumanB toni("Toni");
		toni.setWeapon(club);
		toni.attack();
		club.setType("some other type of unknown");
		toni.attack();
		club.setType("some another type of unknown");
	}
	return 0;
}