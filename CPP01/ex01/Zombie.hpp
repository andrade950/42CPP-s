#ifndef _ZOMBIE_HPP
# define _ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {
	private:
		std::string _name;
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		void setName(std::string name);

};

Zombie *zombieHorde(int N, std::string name);

#endif // _ZOMBIE_HPP