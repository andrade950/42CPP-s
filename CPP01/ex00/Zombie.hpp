/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:33:53 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/17 13:48:52 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP
# define _ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	private:
		std::string _name;
	public:
		void	announce(void);
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

#endif // _ZOMBIE_HPP