/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 15:28:30 by joaomart          #+#    #+#             */
/*   Updated: 2026/05/11 16:01:16 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    private:
        std::string     _target;
    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        virtual ~RobotomyRequestForm();

        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
        
        std::string     getTarget() const;
        
        void    execute(Bureaucrat const &bureaucrat) const;

        static AForm *createRobotomyRequestForm(std::string const &target)
        {
            return (new RobotomyRequestForm(target));
        }
};

std::ostream    &operator<<(std::ostream &out, RobotomyRequestForm const &form);