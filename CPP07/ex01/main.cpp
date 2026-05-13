/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:51:15 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/13 13:55:02 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
 
// -----------------------------------------------------------------------
// Helper functions
// -----------------------------------------------------------------------
 
static void section(const std::string &title)
{
    std::cout << "\n============================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "============================================\n\n";
}
 
template <typename T>
void    printNewline(const T &) { (void)0; }  // dummy, just to show iter accepts any func
 
void    decrementInt(int &v)   { v -= 1; }
void    decrementFloat(float &v) { v -= 1.0f; }
 
void    printInt(const int &v)         { std::cout << v << " "; }
void    printFloat(const float &v)     { std::cout << v << " "; }
void    printString(const std::string &v) { std::cout << "\"" << v << "\" "; }
void    printChar(const char &v)       { std::cout << v << " "; }
void    toUpperChar(char &v)
{
    if (v >= 'a' && v <= 'z')
        v = static_cast<char>(v - 32);
}
 
int main(void)
{
    // -----------------------------------------------------------------------
    section("1. int array - print, increment, print");
    // -----------------------------------------------------------------------
    {
        int arr[] = {0, 1, 2, 3, 4, 5};
        size_t len = 6;
 
        std::cout << "before: ";
        ::iter(arr, len, printInt);
        std::cout << "\n";
 
        ::iter(arr, len, incrementValue<int>);
        std::cout << "after increment: ";
        ::iter(arr, len, printInt);
        std::cout << "\n";
 
        ::iter(arr, len, decrementInt);
        std::cout << "after decrement: ";
        ::iter(arr, len, printInt);
        std::cout << "\n";
    }
 
    // -----------------------------------------------------------------------
    section("2. float array - template vs function");
    // -----------------------------------------------------------------------
    {
        float arr[] = {2.4f, 3.2f, 5.6f, 10.0f};
        size_t len = 4;
 
        std::cout << "via template  : ";
        ::iter(arr, len, printValue<float>);
        std::cout << "\n";
 
        std::cout << "via function  : ";
        ::iter(arr, len, printFloat);
        std::cout << "\n";
 
        ::iter(arr, len, incrementValue<float>);
        std::cout << "after +1 each : ";
        ::iter(arr, len, printFloat);
        std::cout << "\n";
    }
 
    // -----------------------------------------------------------------------
    section("3. string array");
    // -----------------------------------------------------------------------
    {
        std::string arr[] = {"Hello", "World", "42", "School", "C++"};
        size_t len = 5;
 
        std::cout << "via template : ";
        ::iter(arr, len, printValue<std::string>);
        std::cout << "\n";
 
        std::cout << "via function : ";
        ::iter(arr, len, printString);
        std::cout << "\n";
    }
 
    // -----------------------------------------------------------------------
    section("4. char array - print then toUpper");
    // -----------------------------------------------------------------------
    {
        char arr[] = {'h', 'e', 'l', 'l', 'o'};
        size_t len = 5;
 
        std::cout << "before toUpper: ";
        ::iter(arr, len, printChar);
        std::cout << "\n";
 
        ::iter(arr, len, toUpperChar);
        std::cout << "after toUpper : ";
        ::iter(arr, len, printChar);
        std::cout << "\n";
    }
 
    // -----------------------------------------------------------------------
    section("5. length = 0 (empty array - must not crash)");
    // -----------------------------------------------------------------------
    {
        int arr[] = {1, 2, 3};
        std::cout << "iter with length=0: ";
        ::iter(arr, 0, printInt);
        std::cout << "(nothing printed)\n";
        std::cout << "[OK] did not crash\n";
    }
 
    // -----------------------------------------------------------------------
    section("6. length = 1 (single element)");
    // -----------------------------------------------------------------------
    {
        int arr[] = {99};
        std::cout << "single element: ";
        ::iter(arr, 1, printInt);
        std::cout << "\n";
        ::iter(arr, 1, incrementValue<int>);
        std::cout << "after increment: ";
        ::iter(arr, 1, printInt);
        std::cout << "\n";
    }
 
    // -----------------------------------------------------------------------
    section("7. const array - read-only function on const data");
    // -----------------------------------------------------------------------
    {
        const int arr[] = {10, 20, 30, 40};
        size_t len = 4;
        std::cout << "const int array: ";
        ::iter(arr, len, printValue<int>);
        std::cout << "\n";
    }
 
    std::cout << "\n";
    return 0;
}
