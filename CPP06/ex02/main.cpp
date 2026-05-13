/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:53:04 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/13 13:40:52 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <sstream>
 
class D : public Base {};   // unknown type, not A/B/C
 
static void printHeader(const std::string &title)
{
    std::cout << "\n============================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "============================================\n\n";
}
 
static void testBoth(Base *p, const std::string &label)
{
    std::cout << "[" << label << "] via pointer   : ";
    identify(p);
    std::cout << "[" << label << "] via reference : ";
    identify(*p);
}
 
int main()
{
    std::srand(time(0));
 
    // -----------------------------------------------------------------------
    printHeader("1. Direct instances (known type)");
    // -----------------------------------------------------------------------
    // Ensures each type is identified correctly at least once.
    {
        Base *a = new A();
        Base *b = new B();
        Base *c = new C();
 
        testBoth(a, "A");
        testBoth(b, "B");
        testBoth(c, "C");
 
        delete a;
        delete b;
        delete c;
    }
 
    // -----------------------------------------------------------------------
    printHeader("2. generate() - random type (5 times)");
    // -----------------------------------------------------------------------
    // Tests the normal exercise flow: generate + identify.
    {
        for (int i = 0; i < 5; i++)
        {
            Base *p = generate();
            std::cout << "generate() #" << i + 1 << ":\n";
            std::cout << "  via pointer   : "; identify(p);
            std::cout << "  via reference : "; identify(*p);
            delete p;
        }
    }
 
    // -----------------------------------------------------------------------
    printHeader("3. pointer vs reference - results must match");
    // -----------------------------------------------------------------------
    // For the same object, pointer and reference must give the same result.
    {
        for (int i = 0; i < 6; i++)
        {
            Base *p = generate();
            std::ostringstream ptr_result, ref_result;
 
            // Capture output of identify(p)
            std::streambuf *old = std::cout.rdbuf(ptr_result.rdbuf());
            identify(p);
            std::cout.rdbuf(old);
 
            // Capture output of identify(*p)
            old = std::cout.rdbuf(ref_result.rdbuf());
            identify(*p);
            std::cout.rdbuf(old);
 
            bool match = (ptr_result.str() == ref_result.str());
            std::cout << "pointer=[" << ptr_result.str().substr(0, ptr_result.str().size()-1)
                      << "] reference=[" << ref_result.str().substr(0, ref_result.str().size()-1)
                      << "] " << (match ? "[OK]" : "[FAIL] differ!") << "\n";
            delete p;
        }
    }
 
    // -----------------------------------------------------------------------
    printHeader("4. Unknown type (class D is not A/B/C)");
    // -----------------------------------------------------------------------
    // identify must print "not identifiable" or equivalent, must not crash.
    {
        Base *d = new D();
        std::cout << "via pointer   : "; identify(d);
        std::cout << "via reference : "; identify(*d);
        delete d;
    }
 
    // -----------------------------------------------------------------------
    printHeader("5. NULL pointer (identify via pointer)");
    // -----------------------------------------------------------------------
    // identify(Base* p) with NULL must not crash - dynamic_cast<X*>(NULL)
    // returns NULL without exception, so must print "not identifiable".
    // identify(Base& p) with NULL is NOT tested: dereferencing NULL is UB.
    {
        Base *null = NULL;
        std::cout << "via pointer   : "; identify(null);
        std::cout << "(reference with NULL is UB - not tested)\n";
    }
 
    // -----------------------------------------------------------------------
    printHeader("6. Distribution of generate() (30 calls)");
    // -----------------------------------------------------------------------
    // Verifies that generate() produces all three types (not stuck on one).
    {
        int countA = 0, countB = 0, countC = 0, countOther = 0;
        for (int i = 0; i < 30; i++)
        {
            Base *p = generate();
            if      (dynamic_cast<A*>(p)) countA++;
            else if (dynamic_cast<B*>(p)) countB++;
            else if (dynamic_cast<C*>(p)) countC++;
            else                          countOther++;
            delete p;
        }
        std::cout << "A=" << countA << " B=" << countB
                  << " C=" << countC << " Other=" << countOther << "\n";
        if (countA > 0 && countB > 0 && countC > 0)
            std::cout << "[OK] All three types were generated\n";
        else
            std::cout << "[WARN] Some type never appeared (possible with srand)\n";
    }
 
    std::cout << "\n";
    return 0;
}

