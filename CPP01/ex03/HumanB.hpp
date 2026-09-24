#pragma once
#include "Weapon.hpp"
#include <iostream>

class HumanB {
	private:
	std::string _name;
	Weapon *_weapon;
	public:
	void	attack();
	HumanB(std::string);
	void	setWeapon(Weapon& weapon);
	~HumanB();
};