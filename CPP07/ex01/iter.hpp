/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:51:12 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/13 13:54:05 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
 
template <typename T, typename Func>
void    iter(T *array, size_t length, Func f)
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}
 
template <typename T, typename Func>
void    iter(const T *array, size_t length, Func f)
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}
 
template <typename T>
void    incrementValue(T &value)
{
    value += 1;
}
 
template <typename T>
void    printValue(const T &value)
{
    std::cout << value << " ";
}
