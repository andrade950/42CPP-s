/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:04:20 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/13 15:04:21 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal {
	protected:
	std::string _name;
	public:
	Cat();
	Cat(std::string _name);
	~Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);

	std::string	getType() const;
	void		setType(std::string type);
	void	makeSound() const;
};