#pragma once
#include <string>

class Weapon {
private:
	std::string _type;
public:
	const std::string getType() const;
	void	setType(const std::string& type);
	Weapon(std::string);
	~Weapon();
	Weapon& operator=(const Weapon &other);
};