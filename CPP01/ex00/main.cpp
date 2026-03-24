/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:33:40 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/17 13:49:06 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *PointerZombie;
	PointerZombie = newZombie("Helder");
	PointerZombie->announce();
	randomChump("Orlando");
	delete PointerZombie;
	return (0);
}