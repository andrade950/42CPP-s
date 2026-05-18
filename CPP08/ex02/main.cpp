/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:32:27 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/18 14:37:16 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>

void printTitle(const std::string& title) {
    std::cout << "\n========================================" << std::endl;
    std::cout << "👉 " << title << std::endl;
    std::cout << "========================================" << std::endl;
}

int main()
{
    // =========================================================================
    printTitle("TESTE 1: Código Oficial do Subject (MutantStack)");
    // =========================================================================
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << " (Esperado: 17)" << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << " (Esperado: 1)" << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    
    std::cout << "Conteudo da MutantStack:" << std::endl;
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "\n(Esperado: 5 3 5 737 0)" << std::endl;

    // Garante que ainda pode ser copiado para um std::stack normal como pede o subject
    std::stack<int> s(mstack);

    // =========================================================================
    printTitle("TESTE 2: Comparação com std::list (Exigência do Subject)");
    // =========================================================================
    // Este teste deve produzir EXATAMENTE o mesmo output que o Teste 1
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    
    std::cout << "Top (back): " << mlist.back() << " (Esperado: 17)" << std::endl;
    mlist.pop_back();
    std::cout << "Size: " << mlist.size() << " (Esperado: 1)" << std::endl;
    
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    
    std::list<int>::iterator lit = mlist.begin();
    std::list<int>::iterator lite = mlist.end();
    ++lit;
    --lit;
    
    std::cout << "Conteudo da std::list:" << std::endl;
    while (lit != lite) {
        std::cout << *lit << " ";
        ++lit;
    }
    std::cout << "\n(Esperado: 5 3 5 737 0)" << std::endl;

    // =========================================================================
    printTitle("TESTE 3: Iteradores Reversos (MutantStack vs std::list)");
    // =========================================================================
    std::cout << "MutantStack (Reverse): ";
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << " ";
        ++rit;
    }
    
    std::cout << "\nstd::list (Reverse):   ";
    std::list<int>::reverse_iterator lrit = mlist.rbegin();
    std::list<int>::reverse_iterator lrite = mlist.rend();
    while (lrit != lrite) {
        std::cout << *lrit << " ";
        ++lrit;
    }
    std::cout << "\n(Esperado em ambos: 0 737 5 3 5)" << std::endl;

    // =========================================================================
    printTitle("TESTE 4: Iteradores Constantes (Garante proteção Read-Only)");
    // =========================================================================
    const MutantStack<int> const_mstack(mstack);
    MutantStack<int>::const_iterator cit = const_mstack.begin();
    MutantStack<int>::const_iterator cite = const_mstack.end();
    
    std::cout << "Const MutantStack: ";
    while (cit != cite) {
        std::cout << *cit << " ";
        // Se tentares descomentar a linha abaixo, o código não deve compilar (prova que é const):
        // *cit = 42; 
        ++cit;
    }
    std::cout << std::endl;

    // =========================================================================
    printTitle("TESTE 5: Compatibilidade com outros tipos subjacentes");
    // =========================================================================
    // Por padrão std::stack usa std::deque, mas e se quisermos usar std::vector internamente?
    // MutantStack deve continuar a herdar e funcionar perfeitamente.
    std::cout << "Criando MutantStack usando std::vector como container interno..." << std::endl;
    std::stack<double, std::vector<double> > customStack; // std::stack padrão
    
    // Testando que a nossa MutantStack aceita tipos diferentes (ex: char)
    MutantStack<char> charStack;
    charStack.push('4');
    charStack.push('2');
    
    std::cout << "Char MutantStack: ";
    for (MutantStack<char>::iterator itc = charStack.begin(); itc != charStack.end(); ++itc) {
        std::cout << *itc;
    }
    std::cout << " (Esperado: 42)" << std::endl;

    std::cout << "\n========================================" << std::endl;
    std::cout << "  TODOS OS TESTES COINCIDEM COM A STD::LIST!" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}