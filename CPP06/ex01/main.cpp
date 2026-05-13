/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:41:39 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/13 13:40:00 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
 
static void printHeader(const std::string &title)
{
    std::cout << "\n============================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "============================================\n";
}
 
static void checkResult(const Data *original, const Data *recovered)
{
    if (recovered == original)
        std::cout << "[OK] Endereco identico\n";
    else
        std::cout << "[FAIL] Enderecos diferentes!\n";
 
    if (original && recovered && recovered->name == original->name && recovered->value == original->value)
        std::cout << "[OK] Data intact: name=\"" << recovered->name
                  << "\" value=" << recovered->value << "\n";
    else if (original)
        std::cout << "[FAIL] Dados corrompidos!\n";
}
 
int main()
{
    // -----------------------------------------------------------------------
    printHeader("1. Stack Memory");
    // -----------------------------------------------------------------------
    {
        Data d;
        d.name  = "stack";
        d.value = 42;
 
        uintptr_t raw = Serializer::serialize(&d);
        Data     *ptr = Serializer::deserialize(raw);
 
        std::cout << "Original  : " << &d  << "\n";
        std::cout << "Serialized: 0x" << std::hex << raw << std::dec << "\n";
        std::cout << "Recovered : " << ptr << "\n";
        checkResult(&d, ptr);
    }
 
    // -----------------------------------------------------------------------
    printHeader("2. Heap Memory (new/delete)");
    // -----------------------------------------------------------------------
    {
        Data *d  = new Data;
        d->name  = "heap";
        d->value = 999;
 
        uintptr_t raw = Serializer::serialize(d);
        Data     *ptr = Serializer::deserialize(raw);
 
        std::cout << "Original  : " << d   << "\n";
        std::cout << "Serialized: 0x" << std::hex << raw << std::dec << "\n";
        std::cout << "Recovered : " << ptr << "\n";
        checkResult(d, ptr);
        delete d;
    }
 
    // -----------------------------------------------------------------------
    printHeader("3. NULL Pointer (edge case)");
    // -----------------------------------------------------------------------
    {
        Data     *d   = NULL;
        uintptr_t raw = Serializer::serialize(d);
        Data     *ptr = Serializer::deserialize(raw);
 
        std::cout << "Original  : " << d   << "\n";
        std::cout << "Serialized: 0x" << std::hex << raw << std::dec << "\n";
        std::cout << "Recovered : " << ptr << "\n";
 
        if (ptr == NULL)
            std::cout << "[OK] NULL survived the round-trip\n";
        else
            std::cout << "[FAIL] Should be NULL!\n";
    }
 
    // -----------------------------------------------------------------------
    printHeader("4. Serialize -> modify data -> deserialize");
    // -----------------------------------------------------------------------
    // The address is stored, not the data. After modifying the object,
    // deserialize must return the same address (with updated data).
    {
        Data d;
        d.name  = "before";
        d.value = 1;
 
        uintptr_t raw = Serializer::serialize(&d);
 
        d.name  = "after";
        d.value = 2;
 
        Data *ptr = Serializer::deserialize(raw);
 
        if (ptr == &d)
            std::cout << "[OK] Address identical after data modification\n";
        else
            std::cout << "[FAIL] Enderecos diferentes!\n";
 
        if (ptr->name == "after" && ptr->value == 2)
            std::cout << "[OK] Data reflects latest version (name=\""
                      << ptr->name << "\" value=" << ptr->value << ")\n";
        else
            std::cout << "[FAIL] Dados inesperados!\n";
    }
 
    // -----------------------------------------------------------------------
    printHeader("5. Multiple objects simultaneously");
    // -----------------------------------------------------------------------
    // Each pointer must produce a unique raw value.
    {
        Data a, b, c;
        a.name = "alpha";   a.value = 1;
        b.name = "beta";    b.value = 2;
        c.name = "gamma";   c.value = 3;
 
        uintptr_t rawA = Serializer::serialize(&a);
        uintptr_t rawB = Serializer::serialize(&b);
        uintptr_t rawC = Serializer::serialize(&c);
 
        if (rawA != rawB && rawB != rawC && rawA != rawC)
            std::cout << "[OK] Three distinct raw values\n";
        else
            std::cout << "[FAIL] Raw values collided!\n";
 
        checkResult(&a, Serializer::deserialize(rawA));
        checkResult(&b, Serializer::deserialize(rawB));
        checkResult(&c, Serializer::deserialize(rawC));
    }
 
    // -----------------------------------------------------------------------
    printHeader("6. Double round-trip (serialize result of deserialize)");
    // -----------------------------------------------------------------------
    {
        Data d;
        d.name  = "roundtrip";
        d.value = 7;
 
        uintptr_t raw1 = Serializer::serialize(&d);
        Data     *ptr1 = Serializer::deserialize(raw1);
        uintptr_t raw2 = Serializer::serialize(ptr1);
        Data     *ptr2 = Serializer::deserialize(raw2);
 
        if (raw1 == raw2 && ptr1 == ptr2 && ptr2 == &d)
            std::cout << "[OK] Double round-trip consistent\n";
        else
            std::cout << "[FAIL] Inconsistency in double round-trip!\n";
    }
 
    std::cout << "\n";
    return 0;
}
 
