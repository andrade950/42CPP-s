/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:53:53 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 16:07:34 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

static void printHeader(const std::string &title)
{
    std::cout << "\n" << BOLD << CYAN;
    std::cout << "===================================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "===================================================" << RESET << std::endl;
}

static void testInternComprehensive()
{
    printHeader("1. TESTING INTERN FORM CREATION");

    Intern someRandomIntern;
    const int numForms = 4;
    AForm *forms[numForms];

    const std::string formNames[numForms] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
        "invalid form"
    };
    const std::string targets[numForms] = {"garden", "Bender", "Arthur Dent", "nobody"};

    for (int i = 0; i < numForms; i++) {
        std::cout << YELLOW << "\nAttempting to create: " << RESET << formNames[i] << "..." << std::endl;
        try {
            forms[i] = someRandomIntern.makeForm(formNames[i], targets[i]);
            std::cout << GREEN << "Result:\n" << RESET << *forms[i] << std::endl;
        } catch (const std::exception &e) {
            std::cout << RED << "Error: " << RESET << e.what() << std::endl;
            forms[i] = NULL;
        }
    }

    printHeader("2. TESTING BUREAUCRAT INTERACTION");

    Bureaucrat boss("The Boss", 1);
    Bureaucrat junior("Junior Dev", 140);

    for (int i = 0; i < numForms; i++) {
        if (forms[i]) {
            std::cout << "\n--- Processing: " << forms[i]->getName() << " ---" << std::endl;

            junior.signForm(*forms[i]);
            junior.executeForm(*forms[i]);

            boss.signForm(*forms[i]);
            boss.executeForm(*forms[i]);

            delete forms[i];
            std::cout << GREEN << "Form deleted successfully." << RESET << std::endl;
        }
    }
}

static void testEdgeCases()
{
    printHeader("3. EDGE CASES & ROBUSTNESS");

    Intern lucky;
    const std::string names[] = {"", "ROBOTOMY REQUEST", " robotomy request", "robotomy request "};

    for (int i = 0; i < 4; i++) {
        std::cout << YELLOW << "\nTesting [" << names[i] << "]:" << RESET << std::endl;
        try {
            AForm *f = lucky.makeForm(names[i], "Bender");
            delete f;
        } catch (const std::exception &e) {
            std::cout << RED << "Expected error: " << RESET << e.what() << std::endl;
        }
    }
}

int main()
{
    try {
        testInternComprehensive();
        testEdgeCases();
    } catch (const std::exception &e) {
        std::cerr << RED << "CRITICAL ERROR: " << RESET << e.what() << std::endl;
    }

    std::cout << "\n" << BOLD << GREEN << "--- All tests completed ---" << RESET << std::endl;
    return 0;
}
