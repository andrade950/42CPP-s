#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

// deep copy: allocate a brand new Brain and copy its content,
// never copy the pointer itself
Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*(this->brain) = *(other.brain); // deep copy into the existing Brain
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

const Brain* Dog::getBrainAddress() const
{
	return this->brain;
}
