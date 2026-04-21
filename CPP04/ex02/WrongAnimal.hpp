/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:16:08 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/14 13:37:48 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class WrongAnimal {
	private:
	protected:
	std::string _type;
	public:
	WrongAnimal(void);
	WrongAnimal(std::string _name);
	virtual ~WrongAnimal();

	WrongAnimal&		operator=(const WrongAnimal& other);
	std::string	getType() const;
	void		setType(std::string type);
	virtual void	makeSound() const;
};