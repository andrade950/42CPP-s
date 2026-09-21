/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 09:50:04 by joaomart          #+#    #+#             */
/*   Updated: 2026/09/16 09:50:42 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <string>
#include <stack>
#include <sstream>

class RPN
{
    private:
        std::stack<int>     _data;
    public:
        RPN();
        RPN(const std::string& );
        RPN(const RPN&);
        RPN&    operator=(const RPN&);
        ~RPN();
        
        void    applyOperator(char op);
        int     evaluate(const std::string &expression);

};

class Error : public std::exception
{
    private:
        std::string     _msg;
    public:
        Error(const std::string &msg) throw() : _msg(msg){};
        virtual ~Error() throw() {};
        virtual const char *what() const throw() { return _msg.c_str(); }
};
