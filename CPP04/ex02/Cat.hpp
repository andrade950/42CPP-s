/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:04:20 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/14 13:35:55 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
	Brain *brain;
	std::string _name;
	protected:
	public:
	Cat();
	Cat(const Cat&);
	~Cat();
	Cat& operator=(const Cat& other);

	std::string	getType() const;
	void		setType(std::string type);
	void	makeSound() const;
	void		setIdea(unsigned int index, std::string idea);
	std::string	getIdea(unsigned int index);
};