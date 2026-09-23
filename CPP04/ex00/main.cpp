#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Correct polymorphism (Animal / Dog / Cat) ===" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	i->makeSound(); // outputs the Cat sound
	j->makeSound(); // outputs the Dog sound
	meta->makeSound(); // outputs the generic Animal sound

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "=== Extra test: array of Animal* ===" << std::endl;
	Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	for (int k = 0; k < 4; k++)
		animals[k]->makeSound();
	for (int k = 0; k < 4; k++)
		delete animals[k];

	std::cout << std::endl << "=== Wrong polymorphism (WrongAnimal / WrongCat) ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << std::endl;
	// makeSound() is not virtual, so the base version is called here,
	// even though the real object is a WrongCat
	wrongCat->makeSound();
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongCat;

	return 0;
}
