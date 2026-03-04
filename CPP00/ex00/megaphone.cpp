/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 12:02:31 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/04 12:02:39 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int	main(int argc, char *argv[])
{
	int i = 0;
	int j = 1;

	if (argc < 2)
		return (std::cout << "* LOUD AND UNBEARABLE NOISE *" << std::endl, 1);
	while (argv[j])
	{
		while (argv[j][i])
			std::cout << (char)std::toupper(argv[j][i++]);
		i = 0;
		j++;
	}
	std::cout << std::endl;
	return (0);
}