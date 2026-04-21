/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:32:40 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/21 13:14:20 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#include <iostream>
#include <sys/types.h>

Brain::Brain(){
	std::cout << "Brain Created" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain died" << std::endl;
}

Brain::Brain(const Brain& other) {
	*this = other;
}

Brain& Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (uint i = 0 ; i < this->n_idea; i++) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}