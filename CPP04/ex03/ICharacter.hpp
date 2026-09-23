#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

class AMateria; // forward declaration to avoid a circular include

// Pure abstract class ("interface"): only pure virtual functions.
class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
