#include "ClapTrap.hpp"

int main()
{
	{
		std::string target = "BOT2";
		ClapTrap BOT1("BOT1");
		BOT1.attack(target);
		BOT1.beRepaired(2);
		BOT1.takeDamage(10);
		BOT1.takeDamage(2);
		BOT1.attack("BOT2");
	}
	{
		std::string target = "BOT2";
		ClapTrap BOT1;
		BOT1.attack(target);
		BOT1.beRepaired(2);
		BOT1.takeDamage(10);
		BOT1.takeDamage(2);
		BOT1.attack("BOT2");
	}
}