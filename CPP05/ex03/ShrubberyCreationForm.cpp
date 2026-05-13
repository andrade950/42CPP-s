/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:28:38 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 16:06:55 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("Default", 145, 137), _target("Default")
{
    std::cout << "Shrubbery: Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Shrubbery: Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &copy)
    : AForm(copy), _target(copy._target)
{
    std::cout << "Shrubbery: Copy constructor called" << std::endl;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        this->_target = copy._target;
    }

    std::cout << "Shrubbery: Assignment operator called" << std::endl;
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
    // Verifica se o formulário está assinado
    if (!this->getIsSigned())
        throw AForm::FormNotSignedException();

    // Verifica se o bureaucrat tem grade suficiente
    if (executor.getGrade() > this->getExecute())
        throw AForm::GradeTooLowException();

    // Nome do ficheiro
    std::string filename = this->_target + "_shrubbery";

    // Criação e abertura do ficheiro
    std::ofstream file(filename.c_str());

    if (!file.is_open())
        throw std::runtime_error("Could not open shrubbery file");

    // ASCII TREE
    file << "          v .   ._, |_  .," << std::endl;
    file << "       `-._\\/  .  \\ /    |/_" << std::endl;
    file << "           \\  _\\, y | \\//" << std::endl;
    file << "     _\\_.___\\, \\/ -.\\||" << std::endl;
    file << "       `7-,--.`._||  / / ," << std::endl;
    file << "       /'     `-. `./ / |_." << std::endl;
    file << "                 |    |//" << std::endl;
    file << "                 |_    /" << std::endl;
    file << "                 |-   |" << std::endl;
    file << "                 |   =|" << std::endl;
    file << "                 |    |" << std::endl;
    file << "----------------/ ,  . \\--------._" << std::endl;

    file.close();

    std::cout << executor.getName()
              << " executed "
              << this->getName()
              << std::endl;
}

std::ostream &operator<<(std::ostream &out,
    const ShrubberyCreationForm &form)
{
    out << "ShrubberyCreationForm: "
        << form.getName()
        << ", Target: "
        << form.getTarget()
        << ", Signed: "
        << form.getIsSigned();

    return (out);
}