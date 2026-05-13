/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:28:38 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 15:47:48 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default", 145, 137), _target("Default")
{
    std::cout << "Shrubbery: Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Shrubbery: Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "Shrubbery: Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
        std::cout << "Shrubbery: Assignment operator called" << std::endl;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery: Destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    // 1. Verificações de segurança antes de abrir o ficheiro
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();

    if (executor.getGrade() > this->getExecute())
        throw AForm::GradeTooLowTooExecute();

    // 2. Tentativa de criação do ficheiro e escrita da árvore
    try 
    {
        std::string filename = this->getTarget() + "_shrubbery";
        std::ofstream file(filename.c_str());

        if (!file.is_open())
            throw AForm::FileNotOpenedException();
		
        file << "          v .   ._, |_  .," << std::endl;
        file << "       `-._\\/  .  \\ /    |/_" << std::endl;
        file << "           \\  _\\, y | \\//" << std::endl;
        file << "     _\\_.___\\, \\/ -.\\||" << std::endl;
        file << "       `7-,--.`._||  / / ," << std::endl;
        file << "       /'     `-. `./ / |/_." << std::endl;
        file << "                 |    |//" << std::endl;
        file << "                 |_    /" << std::endl;
        file << "                 |-   |" << std::endl;
        file << "                 |   =|" << std::endl;
        file << "                 |    |" << std::endl;
        file << "----------------/ ,  . \\--------._" << std::endl;

        file.close();
        std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Execution error: " << e.what() << std::endl;
        throw; 
    }
}

std::ostream    &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
    std::cout << "ShrubberyCreationForm : " << form.getName() << ", Target: " << form.getTarget() << ", Is signed: " << form.getIsSigned() << std::endl;
    return (out);
};