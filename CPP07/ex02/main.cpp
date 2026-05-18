/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:49:13 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/18 13:44:22 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
 
#define RESET  "\033[0m"
#define GREEN  "\033[32m"
#define RED    "\033[31m"
 
static void result(const std::string &name, bool ok)
{
    std::cout << (ok ? GREEN "[OK]" : RED "[KO]") << RESET
              << " " << name << "\n";
}
 
static void section(const std::string &title)
{
    std::cout << "\n============================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "============================================\n\n";
}
 
int main(void)
{
    // -----------------------------------------------------------------------
    section("1. Default constructor (size 0)");
    // -----------------------------------------------------------------------
    {
        Array<int> a;
        result("size() == 0", a.size() == 0);
        try {
            a[0] = 1;
            result("throws on access to empty array", false);
        } catch (std::exception &e) {
            result("throws on access to empty array", true);
        }
    }
 
    // -----------------------------------------------------------------------
    section("2. Constructor with size - default initialisation");
    // -----------------------------------------------------------------------
    // new T[n]() zero-initialises: ints must be 0, not garbage
    {
        Array<int> a(5);
        result("size() == 5", a.size() == 5);
        bool zeroed = true;
        for (unsigned int i = 0; i < a.size(); i++)
            if (a[i] != 0) zeroed = false;
        result("elements default-initialised to 0", zeroed);
    }
 
    // -----------------------------------------------------------------------
    section("3. operator[] - read and write");
    // -----------------------------------------------------------------------
    {
        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = static_cast<int>(i * 10);
        result("write and read back", a[0] == 0 && a[2] == 20 && a[4] == 40);
 
        // out of bounds: exactly at size
        try {
            a[5] = 99;
            result("throws at index == size", false);
        } catch (std::exception &e) {
            result("throws at index == size", true);
        }
 
        // out of bounds: way beyond
        try {
            a[1000] = 99;
            result("throws at index >> size", false);
        } catch (std::exception &e) {
            result("throws at index >> size", true);
        }
    }
 
    // -----------------------------------------------------------------------
    section("4. Copy constructor - deep copy");
    // -----------------------------------------------------------------------
    {
        Array<int> original(3);
        original[0] = 10; original[1] = 20; original[2] = 30;
 
        Array<int> copy(original);
        result("copy has same size", copy.size() == original.size());
        result("copy has same values", copy[0] == 10 && copy[1] == 20 && copy[2] == 30);
 
        original[1] = 99;
        result("modifying original does not affect copy", copy[1] == 20);
 
        copy[2] = 88;
        result("modifying copy does not affect original", original[2] == 30);
    }
 
    // -----------------------------------------------------------------------
    section("5. Assignment operator - deep copy");
    // -----------------------------------------------------------------------
    {
        Array<int> a(4);
        a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;
 
        Array<int> b(2);
        b[0] = 10; b[1] = 20;
 
        b = a;
        result("after assignment, size matches", b.size() == a.size());
        result("after assignment, values match", b[0] == 1 && b[3] == 4);
 
        a[0] = 100;
        result("modifying source does not affect destination", b[0] == 1);
 
        b[1] = 200;
        result("modifying destination does not affect source", a[1] == 2);
    }
 
    // -----------------------------------------------------------------------
    section("6. Self-assignment");
    // -----------------------------------------------------------------------
    {
        Array<int> a(3);
        a[0] = 7; a[1] = 8; a[2] = 9;
        Array<int> *pa = &a;
        *pa = a;
        result("self-assignment does not corrupt data", a[0] == 7 && a[1] == 8 && a[2] == 9);
        result("self-assignment size unchanged", a.size() == 3);
    }
 
    // -----------------------------------------------------------------------
    section("7. float type");
    // -----------------------------------------------------------------------
    {
        Array<float> a(3);
        a[0] = 1.1f; a[1] = 2.2f; a[2] = 3.3f;
        result("float values stored correctly", a[0] == 1.1f && a[2] == 3.3f);
        Array<float> b(a);
        result("float copy constructor", b[1] == 2.2f);
    }
 
    // -----------------------------------------------------------------------
    section("8. string type");
    // -----------------------------------------------------------------------
    {
        Array<std::string> a(3);
        a[0] = "Hello"; a[1] = "World"; a[2] = "!";
        result("string values stored correctly", a[0] == "Hello" && a[2] == "!");
        Array<std::string> b(a);
        a[0] = "Changed";
        result("string deep copy (original changed, copy intact)", b[0] == "Hello");
    }
 
    // -----------------------------------------------------------------------
    section("9. const Array - read-only access");
    // -----------------------------------------------------------------------
    {
        Array<int> a(3);
        a[0] = 5; a[1] = 6; a[2] = 7;
        const Array<int> ca(a);
        result("const array read access", ca[0] == 5 && ca[2] == 7);
        // ca[0] = 99; // must not compile - operator[] needs const overload
    }
 
    // -----------------------------------------------------------------------
    section("10. size 1 edge case");
    // -----------------------------------------------------------------------
    {
        Array<int> a(1);
        a[0] = 42;
        result("size 1 - read/write", a[0] == 42);
        try {
            a[1] = 0;
            result("size 1 - throws on index 1", false);
        } catch (std::exception &e) {
            result("size 1 - throws on index 1", true);
        }
    }
 
    std::cout << "\n";
    return 0;
}

