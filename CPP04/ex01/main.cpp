#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ARRAY_SIZE 6 // must be even: half Dog, half Cat

int main()
{
	std::cout << "=== delete a Dog/Cat through an Animal* : no leak ===" << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		delete j; // Animal destructor is virtual -> Dog destructor runs too
		delete i;
	}

	std::cout << std::endl << "=== array of Animal, half Dog half Cat ===" << std::endl;
	Animal* animals[ARRAY_SIZE];
	for (int k = 0; k < ARRAY_SIZE; k++)
	{
		if (k % 2 == 0)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}
	for (int k = 0; k < ARRAY_SIZE; k++)
		animals[k]->makeSound();
	for (int k = 0; k < ARRAY_SIZE; k++)
		delete animals[k]; // deleting as Animal, destructors chain correctly

	std::cout << std::endl << "=== deep copy test ===" << std::endl;
	Dog original;
	Dog copy(original); // uses Dog copy constructor -> deep copy of its Brain

	// prove the two Dogs do NOT share the same Brain:
	// changing one must not affect the other. We reach the Brain only
	// through the public interface we already have (makeSound / getType),
	// so instead we simply show both objects live and die independently.
	std::cout << "original type: " << original.getType() << std::endl;
	std::cout << "copy type: " << copy.getType() << std::endl;

	if (original.getBrainAddress() != copy.getBrainAddress())
		std::cout << "Brains have different addresses -> deep copy OK" << std::endl;
	else
		std::cout << "Brains share the same address -> shallow copy (BUG)" << std::endl;

	Cat catOriginal;
	Cat catCopy;
	catCopy = catOriginal; // uses Cat copy assignment operator -> deep copy

	return 0;
}
