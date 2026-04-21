/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:57:50 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/13 15:32:38 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Animal {
	private:
	protected:
	std::string _type;
	public:
	Animal(void);
	Animal(std::string _name);
	Animal(const Animal& other);
	virtual ~Animal();
	Animal&		operator=(const Animal& other);

	std::string	getType() const;
	void		setType(std::string type);
	virtual void	makeSound() const;
};