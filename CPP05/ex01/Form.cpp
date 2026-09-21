/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:31:51 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 14:32:40 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _formName("Default Form"), _isSigned(false), _gradeTosign(150), _gradeToexecute(150)
{
    std::cout << "Form : Default Constructor" << std::endl;
}

Form::Form(const std::string &form_name, int gradeSign, int gradeExecute)
    : _formName(form_name), _isSigned(false), _gradeTosign(gradeSign), _gradeToexecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150 || gradeExecute > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form : Name Constructor" << std::endl;
}

Form::Form(const Form &copy)
    : _formName(copy._formName), _isSigned(copy._isSigned),
      _gradeTosign(copy._gradeTosign), _gradeToexecute(copy._gradeToexecute)
{
    std::cout << "Form : Copy Constructor" << std::endl;
}

Form &Form::operator=(const Form &copy)
{
    // Name and grades are const: only the signed status is copied.
    if (this != &copy)
    {
        _isSigned = copy._isSigned;
        std::cout << "Form : Assignment Operator" << std::endl;
    }
    return (*this);
}

Form::~Form()
{
    std::cout << "Form : Destructor" << std::endl;
}

const std::string &Form::getName() const
{
    return (_formName);
}

bool Form::getIsSigned() const
{
    return (_isSigned);
}

int Form::getSign() const
{
    return (_gradeTosign);
}

int Form::getExecute() const
{
    return (_gradeToexecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeTosign)
        throw Form::GradeTooLowException();
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form name: " << form.getName() << "\n"
        << "Is signed: " << (form.getIsSigned() ? "Yes" : "No") << "\n"
        << "Grade to sign: " << form.getSign() << "\n"
        << "Grade to execute: " << form.getExecute();
    return (out);
}
