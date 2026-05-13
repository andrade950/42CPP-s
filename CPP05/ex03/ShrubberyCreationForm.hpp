/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:32:21 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 16:03:02 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string     _target;
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        virtual ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

        std::string     getTarget() const;
        void    execute(Bureaucrat const &bureaucrat) const;

        static AForm *createShrubberyCreationForm(std::string const &target)
        {
            return (new ShrubberyCreationForm(target));
        }
};
std::ostream    &operator<<(std::ostream &out, const ShrubberyCreationForm &form);