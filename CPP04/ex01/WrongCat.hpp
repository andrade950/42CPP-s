#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat& operator=(const WrongCat& other);
		virtual ~WrongCat();

		// this "hides" WrongAnimal::makeSound instead of overriding it,
		// because the base version is not virtual
		void makeSound() const;
};

#endif
