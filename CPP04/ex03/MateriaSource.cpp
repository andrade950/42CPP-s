#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < KNOWN_MATERIA_SIZE; i++)
		this->knownMateria[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < KNOWN_MATERIA_SIZE; i++)
	{
		if (other.knownMateria[i])
			this->knownMateria[i] = other.knownMateria[i]->clone();
		else
			this->knownMateria[i] = 0;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < KNOWN_MATERIA_SIZE; i++)
		{
			delete this->knownMateria[i];
			if (other.knownMateria[i])
				this->knownMateria[i] = other.knownMateria[i]->clone();
			else
				this->knownMateria[i] = 0;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < KNOWN_MATERIA_SIZE; i++)
		delete this->knownMateria[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < KNOWN_MATERIA_SIZE; i++)
	{
		if (!this->knownMateria[i]) // first free "template" slot
		{
			this->knownMateria[i] = m; // we take ownership of m
			return;
		}
	}
	delete m; // no room to learn it: avoid a leak
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < KNOWN_MATERIA_SIZE; i++)
	{
		if (this->knownMateria[i] && this->knownMateria[i]->getType() == type)
			return this->knownMateria[i]->clone();
	}
	return 0; // unknown type
}
