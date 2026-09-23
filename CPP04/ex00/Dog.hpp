#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		virtual ~Dog();

		// overrides Animal::makeSound with a dog-specific sound
		virtual void makeSound() const;
};

#endif
