#pragma once
#include <iostream>

class ClapTrap {
private:
protected:
	std::string	_name;
	unsigned int	_HP;
	unsigned int	_EP;
	unsigned int	_AD;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	virtual ~ClapTrap();

	virtual void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	ClapTrap& operator=(const ClapTrap& other);
};