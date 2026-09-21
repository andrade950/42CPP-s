/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:28:15 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 16:01:09 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
    std::cout << "Robotomy : Default Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "Robotomy : Name Constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy), _target(copy._target)
{
    std::cout << "Robotomy : Copy Constructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
        std::cout << "Robotomy : Assignment Operator" << std::endl;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "Robotomy : Destructor" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const
{
    return (_target);
}

void RobotomyRequestForm::action() const
{
    // Seed only once per program: reseeding on every call with time(NULL)
    // gives identical results for calls made within the same second.
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        seeded = true;
    }

    std::cout << "BZZZZZ... drilling noises" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "The robotomy of " << _target << " failed" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form)
{
    out << "RobotomyRequestForm: " << form.getName()
        << ", Target: " << form.getTarget()
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No");
    return (out);
}
