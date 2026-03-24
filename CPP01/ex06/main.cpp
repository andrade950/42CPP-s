/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:39:59 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/17 14:40:00 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <iomanip>
#include <string>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Harl Filter : [DEBUG] - [INFO] - [WARNING] - [ERROR]" << std::endl;
        return (1);
    }
    Harl H;
    H.complain(av[1]);
    return (0);
}