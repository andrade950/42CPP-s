/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:24:42 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/18 14:30:48 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>

void printTitle(const std::string& title) {
    std::cout << "\n========================================\n"
              << "👉 " << title << "\n"
              << "========================================" << std::endl;
}

int main()
{
    std::srand(std::time(NULL));

    // -------------------------------------------------------------------------
    printTitle("TESTE 1: Exemplo do Sujeito (Subject)");
    // -------------------------------------------------------------------------
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Conteudo: "; sp.printSpan();
        std::cout << "Shortest span: " << sp.shortestSpan() << " (Esperado: 2)" << std::endl;
        std::cout << "Longest span: "  << sp.longestSpan()  << " (Esperado: 14)" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro inesperado: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    printTitle("TESTE 2: Teste Massivo (15.000+ numeros)");
    // -------------------------------------------------------------------------
    try {
        unsigned int size = 20000;
        Span sp(size);
        std::vector<int> bigVec;

        for (unsigned int i = 0; i < size; i++) {
            bigVec.push_back(std::rand());
        }

        std::cout << "A tentar inserir " << size << " elementos usando iteradores..." << std::endl;
        sp.addNumber(bigVec.begin(), bigVec.end());
        std::cout << "Insercao concluida com sucesso!" << std::endl;
        
        std::cout << "Shortest span (Massivo): " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span (Massivo): "  << sp.longestSpan()  << " std::endl;" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro no teste massivo: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    printTitle("TESTE 3: Iteradores de outros contentores (std::list)");
    // -------------------------------------------------------------------------
    try {
        std::list<int> myList;
        myList.push_back(100);
        myList.push_back(200);
        myList.push_back(105); // Menor diferenca sera 5 (105 - 100)

        Span sp(10);
        sp.addNumber(myList.begin(), myList.end());
        
        std::cout << "Conteudo do Span vindo de uma std::list: "; sp.printSpan();
        std::cout << "Shortest span: " << sp.shortestSpan() << " (Esperado: 5)" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro com std::list: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    printTitle("TESTE 4: Robustez das Excecoes");
    // -------------------------------------------------------------------------
    // Caso A: Tentar estourar o limite com iteradores
    try {
        Span sp(3);
        std::vector<int> v(5, 42); // Cria vector com 5 elementos
        std::cout << "A tentar enfiar 5 elementos num Span de tamanho 3..." << std::endl;
        sp.addNumber(v.begin(), v.end());
    } catch (const std::exception& e) {
        std::cout << "Sucesso! Excecao capturada: " << e.what() << std::endl;
    }

    // Caso B: Procura spans sem numeros suficientes
    try {
        Span sp(5);
        sp.addNumber(42);
        std::cout << "A tentar calcular span com apenas 1 elemento..." << std::endl;
        sp.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Sucesso! Excecao capturada: " << e.what() << std::endl;
    }

    // -------------------------------------------------------------------------
    printTitle("TESTE 5: Deep Copy (Copias Profundas - Ortodoxo)");
    // -------------------------------------------------------------------------
    try {
        Span origin(3);
        origin.addNumber(10);
        origin.addNumber(20);

        // Copia por Construtor
        Span copy1(origin);
        // Copia por Atribuicao
        Span copy2;
        copy2 = origin;

        // Modificar a origem nao pode afetar as copias
        origin.addNumber(30);

        std::cout << "Origem (deve ter 3): "; origin.printSpan();
        std::cout << "Copia 1 (deve ter 2): "; copy1.printSpan();
        std::cout << "Copia 2 (deve ter 2): "; copy2.printSpan();
        
        if (copy1.longestSpan() == 10 && origin.longestSpan() == 20) {
            std::cout << "✅ Sucesso! As copias sao profundas e independentes." << std::endl;
        } else {
            std::cout << "❌ ERRO! A copia alterou a origem." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Erro no teste de copia: " << e.what() << std::endl;
    }

    std::cout << "\n========================================" << std::endl;
    std::cout << "  FIM DE TODOS OS TESTES" << std::endl;
    std::cout << "========================================" << std::endl;

    return 0;
}