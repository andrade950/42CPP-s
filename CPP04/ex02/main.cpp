#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Animal meta; // would not compile: Animal is now abstract

	std::cout << "=== Animal is abstract, everything else works as before ===" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	i->makeSound();
	j->makeSound();

	delete j;
	delete i;

	return 0;
}
