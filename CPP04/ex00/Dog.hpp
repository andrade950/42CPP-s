/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:13:35 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/13 15:13:43 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal {
	private:
	protected:
	std::string _name;
	public:
	Dog();
	Dog(std::string _name);
	~Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);

	std::string	getType() const;
	void		setType(std::string type);
	void	makeSound() const;
};