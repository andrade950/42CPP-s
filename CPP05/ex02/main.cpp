/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:53:53 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 15:53:55 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

static void printHeader(const std::string &title)
{
    std::cout << "\n" << MAGENTA << "===================================================" << RESET << std::endl;
    std::cout << MAGENTA << "=== " << title << RESET << std::endl;
    std::cout << MAGENTA << "===================================================" << RESET << std::endl;
}

static void testPolymorphicExecution()
{
    printHeader("POLYMORPHIC FORM TEST (ARRAY)");

    Bureaucrat boss("The Boss", 1);

    AForm *forms[] = {
        new ShrubberyCreationForm("Home"),
        new RobotomyRequestForm("Bender"),
        new PresidentialPardonForm("Arthur Dent")
    };

    for (int i = 0; i < 3; i++) {
        std::cout << YELLOW << "\nWorking on: " << forms[i]->getName() << RESET << std::endl;

        std::cout << "1. Attempting execution without signature (must fail):" << std::endl;
        boss.executeForm(*forms[i]);

        std::cout << "2. Signing and executing:" << std::endl;
        boss.signForm(*forms[i]);
        boss.executeForm(*forms[i]);

        delete forms[i];
    }
}

static void testRobotomyLuck()
{
    printHeader("ROBOTOMY 50% CHANCE TEST");

    Bureaucrat tech("Technician", 1);
    RobotomyRequestForm robot("Target_Unit");

    tech.signForm(robot);
    std::cout << "Attempting 6 robotomies to check probability:" << std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << "[" << i + 1 << "] ";
        tech.executeForm(robot);
    }
}

static void testShrubberyVerification()
{
    printHeader("SHRUBBERY FILE TEST");

    Bureaucrat gardener("Gardener", 1);
    ShrubberyCreationForm garden("Backyard");

    gardener.signForm(garden);
    gardener.executeForm(garden);

    std::cout << GREEN << "Check your directory for the 'Backyard_shrubbery' file!" << RESET << std::endl;
}

static void testExecutionConstraints()
{
    printHeader("EXECUTION CONSTRAINTS (GRADE TOO LOW)");

    Bureaucrat intern("Intern", 150);
    Bureaucrat manager("Manager", 50); // can sign Robotomy (72) but cannot execute it (45)
    Bureaucrat director("Director", 45); // can execute Robotomy (exactly 45)

    RobotomyRequestForm form("TopSecretRobot");

    std::cout << YELLOW << "Case 1: Intern tries to execute (not signed):" << RESET << std::endl;
    intern.executeForm(form);

    std::cout << "\n" << YELLOW << "Case 2: Intern tries to sign (grade too low):" << RESET << std::endl;
    intern.signForm(form);

    std::cout << "\n" << YELLOW << "Case 3: Manager signs but cannot execute:" << RESET << std::endl;
    manager.signForm(form);
    manager.executeForm(form);

    std::cout << "\n" << YELLOW << "Case 4: Director (grade 45 == required 45) executes:" << RESET << std::endl;
    director.executeForm(form);
}

int main()
{
    try {
        testPolymorphicExecution();
        testRobotomyLuck();
        testShrubberyVerification();
        testExecutionConstraints();
    } catch (const std::exception &e) {
        std::cerr << RED << "Unexpected Critical Error: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << GREEN << "--- All Office Work Finished ---" << RESET << std::endl;
    return 0;
}
