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

		// virtual so that Dog/Cat versions are called through an Animal* / Animal&
		virtual void makeSound() const;
};

#endif
