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

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

static void printHeader(const std::string &title)
{
    std::cout << "\n" << CYAN << "===================================================" << RESET << std::endl;
    std::cout << CYAN << "=== " << title << RESET << std::endl;
    std::cout << CYAN << "===================================================" << RESET << std::endl;
}

static void testDeepCopy()
{
    printHeader("COPY CONSTRUCTOR & ASSIGNMENT TEST");

    Form original("Original Form", 42, 42);
    Bureaucrat boss("Big Boss", 1);
    boss.signForm(original);

    std::cout << "Original before copy:\n" << original << std::endl;

    Form copy(original);
    std::cout << "Copy of signed form:\n" << copy << std::endl;
    if (copy.getIsSigned() == original.getIsSigned())
        std::cout << GREEN << "[CHECK] Copy constructor kept the signed status." << RESET << std::endl;
    else
        std::cout << RED << "[FAIL] Copy constructor lost the signed status." << RESET << std::endl;

    Form assigned;
    assigned = original;
    if (assigned.getIsSigned() == original.getIsSigned())
        std::cout << GREEN << "[CHECK] Assignment operator kept the signed status." << RESET << std::endl;
    else
        std::cout << RED << "[FAIL] Assignment operator lost the signed status." << RESET << std::endl;
}

static void testBureaucratProgression()
{
    printHeader("BUREAUCRAT PROGRESSION TEST");

    Bureaucrat apprentice("Apprentice", 11);
    Form contract("High Level Contract", 10, 10);

    std::cout << apprentice << std::endl;

    std::cout << YELLOW << "Attempt 1 (Grade 11 vs Requirement 10):" << RESET << std::endl;
    apprentice.signForm(contract);

    std::cout << "Promoting " << apprentice.getName() << "..." << std::endl;
    apprentice.incrementBureaucrat();
    std::cout << "New grade: " << apprentice.getGrade() << std::endl;

    std::cout << YELLOW << "Attempt 2 (Grade 10 vs Requirement 10):" << RESET << std::endl;
    apprentice.signForm(contract);

    if (contract.getIsSigned())
        std::cout << GREEN << "Success: Apprentice promoted and signed the form!" << RESET << std::endl;

    std::cout << YELLOW << "Attempt 3 (already signed):" << RESET << std::endl;
    apprentice.signForm(contract);
}

static void testInvalidForms()
{
    printHeader("FORM CONSTRUCTOR VALIDATION");

    const int grades[][2] = {{1, 1}, {150, 150}, {0, 10}, {10, 0}, {151, 10}, {10, 151}};
    for (int i = 0; i < 6; ++i) {
        std::cout << "Form(sign=" << grades[i][0] << ", exec=" << grades[i][1] << "): ";
        try {
            Form f("Test", grades[i][0], grades[i][1]);
            std::cout << GREEN << "OK" << RESET << std::endl;
        } catch (const std::exception &e) {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
}

static void testConstDestruction()
{
    printHeader("SCOPE & DESTRUCTION TEST");
    {
        Form temp("Temporary", 150, 150);
        std::cout << "Form " << temp.getName() << " created in local scope." << std::endl;
    }
    std::cout << "Form should have been destroyed by now." << std::endl;
}

static void testMassiveBureaucracy()
{
    printHeader("MASSIVE BUREAUCRACY TEST");

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

int main()
{
    try {
        testDeepCopy();
        testBureaucratProgression();
        testInvalidForms();
        testConstDestruction();
        testMassiveBureaucracy();

        printHeader("ORIGINAL BOUNDARY TESTS");
        Bureaucrat low("Low", 150);
        try {
            low.decrementBureaucrat();
        } catch (const std::exception &e) {
            std::cerr << RED << "Caught expected error: " << e.what() << RESET << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << RED << "CRITICAL ERROR: " << e.what() << RESET << std::endl;
    }

    std::cout << "\n" << GREEN << "All tests completed!" << RESET << std::endl;
    return 0;
}
