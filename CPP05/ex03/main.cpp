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
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

// Cores para o terminal
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void printHeader(const std::string& title) {
    std::cout << "\n" << BOLD << CYAN;
    std::cout << "===================================================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "===================================================" << RESET << std::endl;
}

void testInternComprehensive() {
    printHeader("1. TESTING INTERN FORM CREATION");
    
    Intern someRandomIntern;
    const int numForms = 4;
    AForm* forms[numForms];
    
    // Nomes dos formulários conforme esperado pela lógica do Intern
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
        "invalid form"
    };
    
    for (int i = 0; i < numForms; i++) {
        std::cout << YELLOW << "\nAttempting to create: " << RESET << formNames[i] << "..." << std::endl;
        try {
            forms[i] = someRandomIntern.makeForm(formNames[i], "Target_" + formNames[i]);
            if (forms[i])
                std::cout << GREEN << "Result: " << RESET << *forms[i] << std::endl;
        } catch (const std::exception& e) {
            std::cout << RED << "Error: " << RESET << "Intern could not create form: " << e.what() << std::endl;
            forms[i] = NULL;
        }
    }

    printHeader("2. TESTING BUREAUCRAT INTERACTION");
    
    Bureaucrat boss("The Boss", 1);
    Bureaucrat intern_dev("Junior Dev", 140);

    for (int i = 0; i < numForms; i++) {
        if (forms[i]) {
            std::cout << "\n--- Processing: " << forms[i]->getName() << " ---" << std::endl;
            
            // Tentativa de assinatura por alguém de nível baixo
            intern_dev.signForm(*forms[i]);
            
            // Assinatura e Execução pelo Chefe
            boss.signForm(*forms[i]);
            boss.execute(*forms[i]);
            
            // Limpeza de memória
            delete forms[i];
            std::cout << GREEN << "Form deleted successfully." << RESET << std::endl;
        }
    }
}

void testEdgeCases() {
    printHeader("3. EDGE CASES & ROBUSTNESS");
    
    Intern lucky;
    AForm* f;

    std::cout << YELLOW << "Testing empty strings:" << RESET << std::endl;
    f = lucky.makeForm("", "");
    if (f) delete f;

    std::cout << YELLOW << "\nTesting case sensitivity (if applicable):" << RESET << std::endl;
    f = lucky.makeForm("ROBOTOMY REQUEST", "Bender");
    if (f) delete f;
}

int main() {
    try {
        testInternComprehensive();
        testEdgeCases();
    } catch (const std::exception& e) {
        std::cerr << RED << "CRITICAL ERROR: " << RESET << e.what() << std::endl;
    }

    std::cout << "\n" << BOLD << GREEN << "--- All tests completed ---" << RESET << std::endl;
    return 0;
}