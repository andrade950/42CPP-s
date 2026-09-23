#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

// Holds the "thoughts" of an animal. Dog and Cat each own one
// via a pointer, so we can test deep-copy behaviour.
class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		void setIdea(int index, const std::string& idea);
		std::string getIdea(int index) const;
};

#endif
