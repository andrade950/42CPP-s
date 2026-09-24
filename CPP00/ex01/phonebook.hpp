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