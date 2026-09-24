#include "HumanB.hpp"

void HumanB::attack(){
	if (this->_weapon == NULL || this->_weapon->getType().length() == 0) {

		std::cout << this->_name << " attacks with their hands" << std::endl;
	}
	else {
		std::cout << this->_name << " attacks with their "
			<< this->_weapon->getType() << std::endl;
	}
}

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

HumanB::~HumanB() {};