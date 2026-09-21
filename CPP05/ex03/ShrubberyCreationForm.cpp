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

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
    std::cout << "Shrubbery: Default Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Shrubbery: Name Constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy), _target(copy._target)
{
    std::cout << "Shrubbery: Copy Constructor" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
        std::cout << "Shrubbery: Assignment Operator" << std::endl;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubbery: Destructor" << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

void ShrubberyCreationForm::action() const
{
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());

    if (!file.is_open())
        throw FileNotOpenedException();

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
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form)
{
    out << "ShrubberyCreationForm: " << form.getName()
        << ", Target: " << form.getTarget()
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No");
    return (out);
}
