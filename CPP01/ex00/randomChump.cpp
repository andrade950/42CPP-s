#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie staticZombie(name);
	staticZombie.announce();
}