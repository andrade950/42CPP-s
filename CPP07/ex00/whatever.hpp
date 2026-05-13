/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:45:35 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/13 13:45:49 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

template <typename T>void swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>void swap(T*& x, T*& y)
{
    if (x == NULL || y == NULL )
        return ;
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>T max(T x, T y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

template <typename T>T min(T x, T y)
{
    if (x < y)
        return (x);
    else
        return (y);
}