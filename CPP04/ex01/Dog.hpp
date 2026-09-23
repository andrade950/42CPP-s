#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* brain; // each Dog owns its own Brain instance

	public:
		Dog();
		Dog(const Dog& other);
		Dog& operator=(const Dog& other);
		virtual ~Dog();

		virtual void makeSound() const;

		// exposed only to prove deep copies work in tests (not required by subject)
		const Brain* getBrainAddress() const;
};

#endif
