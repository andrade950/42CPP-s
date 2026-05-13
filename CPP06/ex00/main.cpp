/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 11:53:51 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/13 11:57:14 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
 
static void test(const std::string &input)
{
    std::cout << "Input: [" << input << "]\n";
    ScalarConverter::convert(input);
    std::cout << std::endl;
}
 
static void section(const std::string &title)
{
    std::cout << "\n========== " << title << " ==========\n\n";
}
 
int main()
{
    // -----------------------------------------------------------------------
    section("CHAR LITERALS");
    // -----------------------------------------------------------------------
    test("a");         // lowercase
    test("Z");         // uppercase
    test("*");         // printable symbol
    test(" ");         // space (displayable? borderline - ASCII 32)
 
    // -----------------------------------------------------------------------
    section("INT LITERALS");
    // -----------------------------------------------------------------------
    test("0");
    test("42");
    test("-42");
    test("+42");       // explicit plus sign
    test("2147483647");  // INT_MAX
    test("-2147483648"); // INT_MIN
 
    // -----------------------------------------------------------------------
    section("FLOAT LITERALS");
    // -----------------------------------------------------------------------
    test("0.0f");
    test("42.0f");
    test("-42.5f");
    test("+1.5f");     // explicit plus sign
    test(".5f");       // no leading digit  <-- BUG: isFloat has n_count check, but dot at pos 0 may be tricky
    test("42.f");      // no decimal digits after dot
    test("0.1f");
 
    // -----------------------------------------------------------------------
    section("DOUBLE LITERALS");
    // -----------------------------------------------------------------------
    test("0.0");
    test("42.0");
    test("-42.5");
    test("+1.5");      // explicit plus sign
    test(".5");        // no leading digit
    test("42.");       // no decimal digits after dot
    test("0.1");
 
    // -----------------------------------------------------------------------
    section("PSEUDO LITERALS - FLOAT");
    // -----------------------------------------------------------------------
    test("nanf");
    test("+inff");
    test("-inff");
    test("inff");      // no sign
 
    // -----------------------------------------------------------------------
    section("PSEUDO LITERALS - DOUBLE");
    // -----------------------------------------------------------------------
    test("nan");
    test("+inf");
    test("-inf");
    test("inf");       // no sign
 
    // -----------------------------------------------------------------------
    section("EDGE CASES - OVERFLOW / IMPOSSIBLE");
    // -----------------------------------------------------------------------
    test("999999999999999999999999");  // massive overflow -> atoi wraps, bad result
    test("-999999999999999999999999"); // negative overflow
 
    // -----------------------------------------------------------------------
    section("EDGE CASES - INVALID INPUT");
    // -----------------------------------------------------------------------
    test("");           // empty string
    test("abc");        // pure string, length > 1 -> not char, not number
    test("42abc");      // trailing non-numeric
    test("--42");       // double minus
    test("++42");       // double plus
    test("42.4.2");     // multiple dots
    test("42.4.2f");    // multiple dots float
    test("f42.0");      // leading 'f' before digits -> length > 1, not char, not number
    test("1e10");       // scientific notation (not supported by subject)
    test("1e10f");      // same, float version
 
    // -----------------------------------------------------------------------
    section("SUBJECT EXAMPLES (must match exactly)");
    // -----------------------------------------------------------------------
    // ./convert 0     -> char: Non displayable | int: 0 | float: 0.0f | double: 0.0
    test("0");
    // ./convert nan   -> char: impossible | int: impossible | float: nanf | double: nan
    test("nan");
    // ./convert 42.0f -> char: '*' | int: 42 | float: 42.0f | double: 42.0
    test("42.0f");
 
    return 0;
}
