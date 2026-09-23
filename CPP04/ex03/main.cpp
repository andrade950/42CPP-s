#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	std::cout << "=== Subject example ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << std::endl << "=== Extra tests ===" << std::endl;

	// unknown type -> createMateria must return 0
	IMateriaSource* src2 = new MateriaSource();
	AMateria* unknown = src2->createMateria("fire");
	if (unknown == 0)
		std::cout << "createMateria(\"fire\") correctly returned 0" << std::endl;
	delete unknown; // delete on a null pointer is safe, no-op

	// full inventory: 5th equip should do nothing
	src2->learnMateria(new Ice());
	Character* alice = new Character("alice");
	for (int i = 0; i < 5; i++)
	{
		AMateria* ice = src2->createMateria("ice");
		alice->equip(ice);
		if (i == 4)
			delete ice; // inventory was full, we still own this one -> free it
	}
	for (int i = 0; i < 4; i++)
		alice->use(i, *alice); // alice uses ice bolts on herself

	// unequip must not delete the Materia -> WE must save the pointer first
	// and delete it ourselves, exactly as the subject warns.
	Character henry("henry");
	AMateria* handed = src2->createMateria("ice");
	henry.equip(handed); // goes into slot 0
	henry.unequip(0);    // Character does NOT delete it
	delete handed;        // WE delete it since we kept the address -> no leak
	std::cout << "unequip(0) done, materia freed by the caller -> no leak" << std::endl;

	// deep copy of a Character
	Character bob2("bob2");
	bob2.equip(src2->createMateria("ice"));
	Character bob2Copy(bob2); // copy constructor -> deep copy
	bob2Copy.use(0, bob2Copy);

	// copy assignment of a Character (old Materias must be freed first)
	Character carl("carl");
	carl.equip(src2->createMateria("ice"));
	carl = bob2; // assignment -> deletes carl's old materia, deep-copies bob2's

	delete alice;
	delete src2;

	return 0;
}
