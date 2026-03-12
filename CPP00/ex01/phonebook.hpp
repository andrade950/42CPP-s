/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 11:43:02 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/12 10:16:08 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_
#define PHONEBOOK_HPP_

# include "utils.hpp"
# include "contact.hpp"

# include <cstdlib>
# include <cctype>
# include <csignal>
# include <iostream>
# include <sstream>

class Phonebook
{
	private:
		Contact _contacts[8];
		int		_index;
	public:
		Phonebook(void);
		void	add(Contact contact);
		void	search();
		void	print(Contact contact);
		Contact	get_contact(int index);
};

bool	GetPrompt(std::string msg, std::string &var);

#endif