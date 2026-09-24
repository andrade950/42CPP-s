#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("DEFAULT") {
	_HP = 100; _EP = 100; _AD = 30;
	std::cout << "[FragTrap] " << _name << " criado." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_HP = 100; _EP = 100; _AD = 30;
	std::cout << "[FragTrap] " << _name << " criado." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "[FragTrap] Copiado." << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "[FragTrap] " << _name << " destruído." << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "[FragTrap] " << _name << " pede um High Five! ✋" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}