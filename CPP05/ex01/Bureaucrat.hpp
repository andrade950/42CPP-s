/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 11:57:09 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 15:07:48 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class Form;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &copy);

        const std::string   &getName() const;
        int                 getGrade() const;

        void                incrementBureaucrat();
        void                decrementBureaucrat();

        void                signForm(Form &form);

        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Grade is too high");
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Grade is too low");
                }
        };

        class FormAlreadySigned : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("form already signed");
                }
        };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
