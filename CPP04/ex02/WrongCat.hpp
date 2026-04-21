/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:21:41 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/14 13:38:06 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	protected:
	std::string _name;
	public:
	WrongCat();
	WrongCat(std::string _name);
	~WrongCat();
	WrongCat& operator=(const WrongCat& other);
	std::string	getType() const;
	void		setType(std::string type);
	void	makeSound() const;
};