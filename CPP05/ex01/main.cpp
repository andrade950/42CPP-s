/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:48:55 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 15:48:57 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <vector>

// Cores para facilitar a leitura no terminal
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

void printHeader(const std::string& title) {
    std::cout << "\n" << CYAN << "===================================================" << RESET << std::endl;
    std::cout << CYAN << "=== " << title << RESET << std::endl;
    std::cout << CYAN << "===================================================" << RESET << std::endl;
}

void testDeepCopy() {
    printHeader("COPY CONSTRUCTOR & ASSIGNMENT TEST");
    
    Form original("Original Form", 42, 42);
    Bureaucrat boss("Big Boss", 1);
    boss.signForm(original);

    std::cout << "Original before copy: " << original << std::endl;

    // Testando construtor de cópia
    Form copy(original);
    std::cout << "Copy of signed form: " << copy << std::endl;

    if (copy.getIsSigned() == original.getIsSigned())
        std::cout << GREEN << "[CHECK] Status de assinatura copiado com sucesso." << RESET << std::endl;
}

void testBureaucratProgression() {
    printHeader("BUREAUCRAT PROGRESSION TEST");

    Bureaucrat apprentice("Apprentice", 11);
    Form contract("High Level Contract", 10, 10);

    std::cout << apprentice << std::endl;
    
    // Tentativa 1: Falha
    std::cout << YELLOW << "Attempt 1 (Grade 11 vs Requirement 10):" << RESET << std::endl;
    apprentice.signForm(contract);

    // Evolução
    std::cout << "Promoting " << apprentice.getName() << "..." << std::endl;
    apprentice.incrementBureaucrat();
    std::cout << "New grade: " << apprentice.getGrade() << std::endl;

    // Tentativa 2: Sucesso
    std::cout << YELLOW << "Attempt 2 (Grade 10 vs Requirement 10):" << RESET << std::endl;
    apprentice.signForm(contract);
    
    if (contract.getIsSigned())
        std::cout << GREEN << "Success: Apprentice promoted and signed the form!" << RESET << std::endl;
}

void testConstDestruction() {
    printHeader("SCOPE & DESTRUCTION TEST");
    {
        Form temp("Temporary", 150, 150);
        std::cout << "Form " << temp.getName() << " created in local scope." << std::endl;
    }
    std::cout << "Form should have been destroyed by now." << std::endl;
}

void testMassiveBureaucracy() {
    printHeader("MASSIVE BUREAUCRACY TEST");
    
    // Testar se múltiplos burocratas podem interagir com o mesmo formulário
    Form taxLaw("Tax Law 2026", 1, 1);
    std::vector<Bureaucrat> office;
    office.push_back(Bureaucrat("Junior", 150));
    office.push_back(Bureaucrat("Senior", 50));
    office.push_back(Bureaucrat("CEO", 1));

    for (size_t i = 0; i < office.size(); ++i) {
        std::cout << "Testing with: " << office[i] << std::endl;
        office[i].signForm(taxLaw);
        if (taxLaw.getIsSigned()) {
            std::cout << GREEN << "Form signed by " << office[i].getName() << RESET << std::endl;
            break;
        }
    }
}

int main() {
    try {
        testDeepCopy();
        testBureaucratProgression();
        testConstDestruction();
        testMassiveBureaucracy();
        
        // Seus testes originais revisados
        printHeader("ORIGINAL BOUNDARY TESTS");
        Bureaucrat low("Low", 150);
        try {
            low.decrementBureaucrat();
        } catch (const std::exception& e) {
            std::cerr << RED << "Caught expected error: " << e.what() << RESET << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << RED << "CRITICAL ERROR: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << GREEN << "All tests completed!" << RESET << std::endl;
    return 0;
}