#include "Weapon.hpp"

void Weapon::setType(const std::string& type)
{
	this->_type = type;
}

const std::string Weapon::getType() const
{
	return (this->_type);
}

Weapon& Weapon::operator=(const Weapon &other)
{
	if (this != &other)
		this->_type = other.getType();
	return (*this);

}

Weapon::Weapon(std::string type) {
	this->_type = type;
}

Weapon::~Weapon() {}