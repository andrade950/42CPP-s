/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 14:31:51 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 15:58:28 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _formName("Default Form"), _isSigned(false), _gradeTosign(150), _gradeToexecute(150)
{
    std::cout << "AForm : Default Constructor" << std::endl;
}

AForm::AForm(const std::string &form_name, int gradeSign, int gradeExecute)
    : _formName(form_name), _isSigned(false), _gradeTosign(gradeSign), _gradeToexecute(gradeExecute)
{
    if (gradeSign < 1 || gradeExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeSign > 150 || gradeExecute > 150)
        throw AForm::GradeTooLowException();
    std::cout << "AForm : Name Constructor" << std::endl;
}

AForm::AForm(const AForm &copy)
    : _formName(copy._formName), _isSigned(copy._isSigned),
      _gradeTosign(copy._gradeTosign), _gradeToexecute(copy._gradeToexecute)
{
    std::cout << "AForm : Copy Constructor" << std::endl;
}

AForm &AForm::operator=(const AForm &copy)
{
    // Name and grades are const: only the signed status is copied.
    if (this != &copy)
    {
        _isSigned = copy._isSigned;
        std::cout << "AForm : Assignment Operator" << std::endl;
    }
    return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm : Destructor" << std::endl;
}

const std::string &AForm::getName() const
{
    return (_formName);
}

bool AForm::getIsSigned() const
{
    return (_isSigned);
}

int AForm::getSign() const
{
    return (_gradeTosign);
}

int AForm::getExecute() const
{
    return (_gradeToexecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeTosign)
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
    if (!_isSigned)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > _gradeToexecute)
        throw AForm::GradeTooLowException();
    action();
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "Form name: " << form.getName() << "\n"
        << "Is signed: " << (form.getIsSigned() ? "Yes" : "No") << "\n"
        << "Grade to sign: " << form.getSign() << "\n"
        << "Grade to execute: " << form.getExecute();
    return (out);
}
