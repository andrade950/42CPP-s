#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
}

// type is const: assigning a Materia to another must NOT change its type,
// so operator= simply does nothing to "type" (nothing else to copy either).
AMateria& AMateria::operator=(const AMateria& other)
{
	(void)other;
	return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
