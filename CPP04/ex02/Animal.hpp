#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

// Base class for every animal in the zoo.
class Animal
{
	protected:
		std::string type; // holds the species name, e.g. "Dog" or "Cat"

	public:
		Animal();
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal();

		std::string getType() const;

		// pure virtual: makes Animal an abstract class, it can no longer be
		// instantiated directly (creating a bare Animal makes no sense).
		virtual void makeSound() const = 0;
};

#endif
