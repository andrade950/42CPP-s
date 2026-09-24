#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#pragma once
#include <iostream>
#include <string>

class ClapTrap {
	private:
	std::string _name ;
	unsigned int	_HP;
	unsigned int	_EP;
	unsigned int	_AD;
	
	public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	ClapTrap& operator=(const ClapTrap& other);
};
#endif