/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:42:57 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/13 12:43:03 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdint.h>
#include "Data.hpp"

class   Serializer
{
    private:
        Serializer(void);
        Serializer(Serializer& );
        Serializer& operator=(Serializer& copy);
        ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};