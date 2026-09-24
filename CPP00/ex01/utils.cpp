#include <iostream>
#include <csignal>
#include <sstream>

void	HandleSignal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

int	Stoi(std::string & s)
{
	int	i = 0;
	try {
		std::istringstream iss(s);
		if (!(iss >> i))
			return -1;
	}
	catch (...) {
		return -1;
	}
	return i;
}

bool IsNumber(std::string str)
{
	if (str.empty())
		return false;
	for (int i = 0; i < (int)str.length() ;i++)
	{
		if (std::isdigit(str[i]) == 0)
			return false;
	}
	return true;
}

void	Display()
{
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|                Phonebook                  |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|         To Add Contact type ADD           |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|       To Search Contact type SEARCH       |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
	std::cout << "|           For Exiting type EXIT           |" << std::endl;
	std::cout << "|___________________________________________|" << std::endl;
}