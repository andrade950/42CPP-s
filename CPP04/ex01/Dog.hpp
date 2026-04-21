/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:13:35 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/13 16:22:08 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
	Brain* brain;

	public:
	Dog();
	Dog(const Dog&);
	~Dog();
	Dog& operator=(const Dog& other);

	void	makeSound() const;

	std::string	getType() const;
	void		setType(std::string type);
	void		setIdea(unsigned int index, std::string idea);
	std::string	getIdea(unsigned int index) const;
};