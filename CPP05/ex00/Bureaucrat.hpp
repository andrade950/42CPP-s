/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:57:09 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 14:22:06 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
        const   std::string _name;
        int     _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(Bureaucrat const &copy);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &copy);
    //getter & setter
        std::string     getName() const;
        int             getGrade() const;
        void            incrementBureaucrat();
        void            decrementBureaucrat();
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Grade is too High");
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw ()
                {
                    return ("Grade is too Low");
                }
        };
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat); 