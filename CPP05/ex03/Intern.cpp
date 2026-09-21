/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:58:08 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 15:59:06 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// The factory functions live here, so the forms don't need to know about Intern.
namespace
{
    AForm *createShrubbery(const std::string &target)
    {
        return (new ShrubberyCreationForm(target));
    }

    AForm *createRobotomy(const std::string &target)
    {
        return (new RobotomyRequestForm(target));
    }

    AForm *createPardon(const std::string &target)
    {
        return (new PresidentialPardonForm(target));
    }
}

Intern::Intern()
{
    std::cout << "Intern : Default Constructor" << std::endl;
}

Intern::Intern(const Intern &copy)
{
    (void)copy;
    std::cout << "Intern : Copy Constructor" << std::endl;
}

Intern &Intern::operator=(const Intern &copy)
{
    (void)copy;
    std::cout << "Intern : Assignment Operator" << std::endl;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern : Destructor" << std::endl;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
    typedef AForm *(*FormCreator)(const std::string &);

    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    const FormCreator creators[3] = {
        &createShrubbery,
        &createRobotomy,
        &createPardon
    };

    for (int i = 0; i < 3; i++)
    {
        if (names[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (creators[i](target));
        }
    }
    std::cout << "Intern cannot create \"" << formName << "\": unknown form" << std::endl;
    throw FormCreationException();
}
