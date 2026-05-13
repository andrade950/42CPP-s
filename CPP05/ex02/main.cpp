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
#include <vector>

// Cores para clareza
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

void printHeader(const std::string& title) {
    std::cout << "\n" << MAGENTA << "===================================================" << RESET << std::endl;
    std::cout << MAGENTA << "=== " << title << RESET << std::endl;
    std::cout << MAGENTA << "===================================================" << RESET << std::endl;
}

void testPolymorphicExecution() {
    printHeader("POLYMORPHIC FORM TEST (ARRAY)");

    Bureaucrat boss("The Boss", 1);
    
    // Criando diferentes formulários e tratando-os como a classe base AForm
    AForm* forms[] = {
        new ShrubberyCreationForm("Home"),
        new RobotomyRequestForm("Bender"),
        new PresidentialPardonForm("Arthur Dent")
    };

    for (int i = 0; i < 3; i++) {
        std::cout << YELLOW << "\nWorking on: " << forms[i]->getName() << RESET << std::endl;
        
        // Tentar executar sem assinar primeiro (deve falhar)
        std::cout << "1. Attempting execution without signature:" << std::endl;
        boss.execute(*forms[i]);

        // Assinar e executar
        std::cout << "2. Signing and executing:" << std::endl;
        boss.signForm(*forms[i]);
        boss.execute(*forms[i]);

        delete forms[i]; // Limpeza de memória
    }
}

void testRobotomyLuck() {
    printHeader("ROBOTOMY 50% CHANCE TEST");
    
    Bureaucrat tech("Technician", 1);
    RobotomyRequestForm robot("Target_Unit");

    tech.signForm(robot);
    std::cout << "Attempting 6 robotomies to check probability:" << std::endl;
    for (int i = 0; i < 6; i++) {
        std::cout << "[" << i + 1 << "] ";
        tech.execute(robot);
    }
}

void testShrubberyVerification() {
    printHeader("SHRUBBERY FILE TEST");
    
    Bureaucrat gardener("Gardener", 1);
    ShrubberyCreationForm garden("Backyard");

    gardener.signForm(garden);
    gardener.execute(garden);
    
    std::cout << GREEN << "Check your directory for 'Backyard_shrubbery' file!" << RESET << std::endl;
}

void testExecutionConstraints() {
    printHeader("EXECUTION CONSTRAINTS (GRADE TOO LOW)");

    Bureaucrat intern("Intern", 150);
    Bureaucrat manager("Manager", 40); // Pode assinar Robotomy (72), mas não executar (45)
    
    RobotomyRequestForm form("TopSecretRobot");

    std::cout << YELLOW << "Case 1: Intern tries to execute (not signed, grade too low):" << RESET << std::endl;
    intern.execute(form);

    std::cout << "\n" << YELLOW << "Case 2: Manager signs but can't execute:" << RESET << std::endl;
    manager.signForm(form);
    manager.execute(form);
}

int main() {
    try {
        // Teste de Polimorfismo (O mais importante do ex02)
        testPolymorphicExecution();

        // Teste de Probabilidade (Robotomy)
        testRobotomyLuck();

        // Teste de Criação de Arquivo (Shrubbery)
        testShrubberyVerification();

        // Teste de Restrições de Nível
        testExecutionConstraints();

    } catch (std::exception& e) {
        std::cerr << RED << "Unexpected Critical Error: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << GREEN << "--- All Office Work Finished ---" << RESET << std::endl;
    return 0;
}