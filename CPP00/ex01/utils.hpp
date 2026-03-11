/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:01:14 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/11 14:01:22 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP_
#define UTILS_HPP_

# include <iostream>
# include <csignal>
# include <sstream>

void	HandleSignal(void);
int		Stoi(std::string & s);
bool	IsNumber(std::string str);
void	Display(void);

#endif 