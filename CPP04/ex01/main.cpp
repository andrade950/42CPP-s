/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:13:47 by joaomart          #+#    #+#             */
/*   Updated: 2026/04/13 16:22:26 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << std::endl << "Test Subject" << std::endl << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		std::cout  << std::endl << "Test Creation of array" << std::endl << std::endl;
		const int num = 5;

		Animal* array[num];
		for (int i = 0 ; i < num; i++) {
			if (i % 2 == 0)
				array[i] = new Dog();
			else
				array[i] = new Cat();
		}
		for (int i = 0 ; i < num; i++) {
			array[i]->makeSound();
		}
		for (int i = 0 ; i < num; i++) {
			delete array[i];
		}
	}
	{
		Animal* Original = new Dog();
		Animal* Copy = new Dog(*dynamic_cast<Dog*>(Original));
		Copy->setType("Barking Dog");
		Dog Copy2 = *dynamic_cast<Dog*>(Original);

		Copy2.setIdea(2, "Hey dawg I got a new idea!");
		dynamic_cast<Dog *>(Copy)->setIdea(2, "OMG! How original idea!");

		std::cout << std::endl << "Test copy depth" << std::endl << std::endl;
		std::cout << "Original: " << Original->getType() << std::endl;
		std::cout << "Copy: " << Copy->getType() << std::endl;
		std::cout << "Copy2: " << Copy2.getType() << std::endl;

		std::cout << "Testing changed Idea" << std::endl;
		std::cout << "Original idea: " << dynamic_cast<Dog*>(Original)->getIdea(2) << std::endl;
		std::cout << "Copy idea: " << dynamic_cast<Dog*>(Copy)->getIdea(2) << std::endl;
		std::cout << "Copy2 idea: " << Copy2.getIdea(2) << std::endl;
		std::cout << std::endl << "Testing NOT changed Idea" << std::endl;
		std::cout << "Original ida: " << dynamic_cast<Dog*>(Original)->getIdea(3) << std::endl;
		std::cout << "Copy idea: " << dynamic_cast<Dog*>(Copy)->getIdea(3) << std::endl;
		std::cout << "Copy2 idea: " << Copy2.getIdea(3) << std::endl;

		delete Original;
		delete Copy;
	}
}