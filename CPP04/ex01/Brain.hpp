/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:33:55 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/13 15:33:56 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Brain {
private:
	static const unsigned int n_idea = 100;
public:
	Brain();
	Brain(std::string idea);
	~Brain();
	Brain& operator=(const Brain &other);
	Brain(const Brain& other);

	std::string ideas[n_idea];
};