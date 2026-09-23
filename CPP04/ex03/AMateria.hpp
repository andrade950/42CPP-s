#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>

class ICharacter; // forward declaration, avoids including ICharacter.hpp here

// Abstract base class for every kind of Materia (spell/item).
class AMateria
{
	protected:
		std::string const type; // "ice", "cure", ... set once at creation

	public:
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();

		std::string const & getType() const; // returns the materia type

		virtual AMateria* clone() const = 0; // pure virtual: makes AMateria abstract
		virtual void use(ICharacter& target); // default: does nothing
};

#endif
