#include "Zombie.hpp"

int	main()
{
	Zombie *PointerZombie;
	PointerZombie = newZombie("Helder");
	PointerZombie->announce();
	randomChump("Orlando");
	delete PointerZombie;
	return (0);
}