#include "Character.hpp"

Character::Character(std::string const & name) : name(name)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		this->inventory[i] = 0; // empty inventory on construction
}

// deep copy: clone every equipped Materia instead of copying the pointer
Character::Character(const Character& other) : name(other.name)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = 0;
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->clearInventory(); // free the Materias we already had
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{
			if (other.inventory[i])
				this->inventory[i] = other.inventory[i]->clone();
			else
				this->inventory[i] = 0;
		}
	}
	return *this;
}

Character::~Character()
{
	this->clearInventory();
}

void Character::clearInventory()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		delete this->inventory[i];
		this->inventory[i] = 0;
	}
}

std::string const & Character::getName() const
{
	return this->name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (!this->inventory[i]) // first empty slot found
		{
			this->inventory[i] = m;
			return;
		}
	}
	// inventory full: do nothing (caller keeps ownership of m)
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
		return;
	// does NOT delete the Materia, just removes it from the inventory
	this->inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
		return;
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
}
