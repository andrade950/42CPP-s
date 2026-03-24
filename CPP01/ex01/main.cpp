/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:59:46 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/17 13:59:49 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int N = 10;
	Zombie *ZombieHorde = zombieHorde(N, "Unnamed Zombie");
	delete [] ZombieHorde;
	return (0);
}