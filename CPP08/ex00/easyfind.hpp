/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 14:04:46 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/18 14:04:50 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <algorithm>

template <typename T>
typename T::iterator    easyfind(T& container, int value)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    
    return (it);
};

template <typename T>
typename T::const_iterator    easyfind(const T& container, int value)
{
    typename T::const_iterator it;

    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::exception();
    
    return (it);
};

