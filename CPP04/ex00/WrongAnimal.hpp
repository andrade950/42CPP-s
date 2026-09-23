#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

// Same as Animal, but makeSound() is NOT virtual on purpose.
// This shows why "virtual" matters for runtime polymorphism.
class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();

		std::string getType() const;

		// no "virtual" here -> no dynamic dispatch through a base pointer/ref
		void makeSound() const;
};

#endif
