#include "Zombie.hpp"

int	main()
{
	int N = 10;
	Zombie *ZombieHorde = zombieHorde(N, "Unnamed Zombie");
	delete [] ZombieHorde;
	return (0);
}