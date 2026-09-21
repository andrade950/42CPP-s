/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:57:11 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 15:50:23 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

static void printHeader(const std::string &title)
{
    std::cout << "\n" << BOLD << CYAN << "===================================================" << RESET << std::endl;
    std::cout << BOLD << "  " << title << RESET << std::endl;
    std::cout << BOLD << CYAN << "===================================================" << RESET << std::endl;
}

// ─── CONSTRUCTOR TESTS ───────────────────────────────────────────────────────

static void testConstructors()
{
    printHeader("1. CONSTRUCTOR VALIDATION");

    const int grades[] = {1, 150, 75, 0, -1, 151, 999};
    const std::string names[] = {"Top", "Bottom", "Middle", "TooHigh", "Negative", "TooLow", "VeryLow"};

    for (int i = 0; i < 7; ++i) {
        std::cout << "[" << i + 1 << "] Testing " << names[i] << " with grade " << grades[i] << ":\n";
        try {
            Bureaucrat b(names[i], grades[i]);
            std::cout << GREEN << "    Success: " << b << RESET << "\n";
        } catch (const std::exception &e) {
            std::cout << RED << "    Exception Caught: " << e.what() << RESET << "\n";
        }
    }
}

// ─── ORTHODOX CANONICAL FORM ─────────────────────────────────────────

static void testCanonicalForm()
{
    printHeader("2. ORTHODOX CANONICAL FORM & CONST NAMES");

    std::cout << YELLOW << "[Step 1] Copy Constructor:" << RESET << "\n";
    Bureaucrat original("Original", 20);
    Bureaucrat copy(original);
    std::cout << "    Original: " << original << "\n";
    std::cout << "    Copy:     " << copy << "\n";

    std::cout << YELLOW << "[Step 2] Assignment Operator (name is const, only the grade changes):" << RESET << "\n";
    Bureaucrat source("Source", 1);
    Bureaucrat target("Target", 150);

    std::cout << "    Before: " << target << "\n";
    target = source;
    std::cout << "    After target = source: " << target << "\n";
}

// ─── INCREMENT / DECREMENT ───────────────────────────────────────────────────

static void testEvolution()
{
    printHeader("3. GRADE EVOLUTION (INC/DEC)");

    Bureaucrat up("PromoteMe", 3);
    std::cout << "Initial: " << up << "\n";
    try {
        while (true) {
            std::cout << "    Incrementing..." << std::endl;
            up.incrementBureaucrat();
            std::cout << "    Current: " << up << "\n";
        }
    } catch (const std::exception &e) {
        std::cout << YELLOW << "    Stop Signal: " << e.what() << RESET << "\n";
    }
    std::cout << "    After failure the grade must still be valid: " << up << "\n";

    Bureaucrat down("DemoteMe", 148);
    std::cout << "\nInitial: " << down << "\n";
    try {
        while (true) {
            std::cout << "    Decrementing..." << std::endl;
            down.decrementBureaucrat();
            std::cout << "    Current: " << down << "\n";
        }
    } catch (const std::exception &e) {
        std::cout << YELLOW << "    Stop Signal: " << e.what() << RESET << "\n";
    }
    std::cout << "    After failure the grade must still be valid: " << down << "\n";
}

// ─── EXCEPTION HIERARCHY ─────────────────────────────────────────────────────

static void testExceptionHierarchy()
{
    printHeader("4. EXCEPTION HIERARCHY");

    std::cout << "Verifying that we can catch specific nested classes:\n";

    try {
        throw Bureaucrat::GradeTooHighException();
    } catch (const Bureaucrat::GradeTooHighException &e) {
        std::cout << GREEN << "    [OK] Caught GradeTooHighException by reference.\n" << RESET;
    } catch (...) {
        std::cout << RED << "    [FAIL] Failed to catch specific exception.\n" << RESET;
    }
}

// ─── DESTRUCTION SEQUENCE ────────────────────────────────────────────────────

static void testDestruction()
{
    printHeader("5. DESTRUCTION SCOPE");
    {
        Bureaucrat b1("ScopeTest_A", 1);
        {
            Bureaucrat b2("ScopeTest_B", 150);
            std::cout << "    B2 is alive.\n";
        }
        std::cout << "    B2 should be dead. B1 is alive.\n";
    }
    std::cout << "    B1 should be dead.\n";
}

// ─── MAIN ────────────────────────────────────────────────────────────────────

int main()
{
    std::cout << BOLD << YELLOW << "--- BUREAUCRAT UNIT TESTS ---" << RESET << std::endl;

    testConstructors();
    testCanonicalForm();
    testEvolution();
    testExceptionHierarchy();
    testDestruction();

    printHeader("ALL TESTS COMPLETED");
    return 0;
}
