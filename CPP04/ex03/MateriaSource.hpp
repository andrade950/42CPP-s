#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define KNOWN_MATERIA_SIZE 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* knownMateria[KNOWN_MATERIA_SIZE]; // "templates" used by clone()

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const & type);
};

#endif
