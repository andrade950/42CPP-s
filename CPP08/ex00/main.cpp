/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:01:42 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/18 14:04:42 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

// Função auxiliar para imprimir cabeçalhos visuais nos testes
void printTitle(const std::string& title) {
    std::cout << "\n--- " << title << " ---" << std::endl;
}

int main( void ) {
    // =========================================================================
    // 1. TESTE COM STD::VECTOR (Modificável e Constante)
    // =========================================================================
    printTitle("Teste com std::vector");
    
    std::vector<int> vec;
    vec.push_back(42);
    vec.push_back(10);
    vec.push_back(5);
    vec.push_back(99);

    // Caso de Sucesso (Vector Normal)
    try {
        std::vector<int>::iterator it = ::easyfind(vec, 5);
        std::cout << "Sucesso! Encontrado o valor: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Erro inesperado no vector: " << e.what() << std::endl;
    }

    // Caso de Sucesso (Vector Constante)
    try {
        const std::vector<int> const_vec(vec);
        std::vector<int>::const_iterator cit = ::easyfind(const_vec, 42);
        std::cout << "Sucesso (Const)! Encontrado o valor: " << *cit << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Erro inesperado no const_vector: " << e.what() << std::endl;
    }

    // Caso de Falha (Elemento inexistente)
    try {
        std::cout << "A tentar procurar o numero 777 (nao existe)..." << std::endl;
        ::easyfind(vec, 777);
        std::cout << "Se vires isto, a excecao nao foi lancada! [ERRO]" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Sucesso! Excecao capturada corretamente (Elemento nao encontrado)." << std::endl;
    }

    // =========================================================================
    // 2. TESTE COM STD::LIST (Prova que o template funciona com outros contentores)
    // =========================================================================
    printTitle("Teste com std::list");

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    try {
        std::list<int>::iterator it = ::easyfind(lst, 2);
        std::cout << "Sucesso na Lista! Encontrado o valor: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Erro na lista: " << e.what() << std::endl;
    }

    // =========================================================================
    // 3. TESTE COM STD::DEQUE
    // =========================================================================
    printTitle("Teste com std::deque (Falha propositada)");

    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);

    try {
        std::cout << "A procurar 500 no deque..." << std::endl;
        ::easyfind(deq, 500);
    }
    catch (const std::exception& e) {
        std::cout << "Sucesso! Excecao capturada no deque." << std::endl;
    }

    std::cout << "\n--- Fim dos testes ---" << std::endl;
    return 0;
}