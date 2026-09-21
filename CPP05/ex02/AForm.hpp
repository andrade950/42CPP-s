/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:27:15 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 15:27:18 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _formName;
        bool                _isSigned;
        const int           _gradeTosign;
        const int           _gradeToexecute;

    protected:
        // Concrete forms only implement the action; the permission checks
        // live in AForm::execute (one single place).
        virtual void        action() const = 0;

    public:
        AForm();
        AForm(const std::string &form_name, int gradeSign, int gradeExecute);
        AForm(const AForm &copy);
        virtual ~AForm();

        AForm &operator=(const AForm &copy);

        const std::string   &getName() const;
        bool                getIsSigned() const;
        int                 getSign() const;
        int                 getExecute() const;

        void                beSigned(const Bureaucrat &bureaucrat);
        void                execute(const Bureaucrat &executor) const;

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

        class FormNotSignedException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return ("Form is not signed");
                }
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);
