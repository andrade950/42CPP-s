/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 14:24:29 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/17 14:27:15 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon {
private:
	std::string _type;
public:
	const std::string getType() const;
	void	setType(const std::string& type);
	Weapon(std::string);
	~Weapon();
	Weapon& operator=(const Weapon &other);
};