/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaomart <joaomart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:41:40 by joaomart          #+#    #+#             */
/*   Updated: 2026/03/12 10:14:35 by joaomart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex
	<< ";amount:" << _amount
	<< "created"
	<< std::endl;
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
}

Account::Account(void)
{
	this->_accountIndex = _nbAccounts++;
	_totalAmount += 0;
	_totalNbDeposits += 0;
	_totalNbWithdrawals += 0;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
	<< "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout
	<< "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t now = time(NULL);
    struct std::tm* localTime = localtime(&now);
	int	year = localTime->tm_year + 1900;
	int	mon= localTime->tm_mon + 1;
	int	day = localTime->tm_mday;
	float hour = localTime->tm_hour;
	float min = localTime->tm_min;
	float sec = localTime->tm_sec;
	std::cout << "["
	<< std::setfill('0') << std::setw(4) << year
	<< std::setfill('0') << std::setw(2) << mon
	<< std::setfill('0') << std::setw(2) << day
	<< '_'
	<< std::setfill('0') << std::setw(2) << hour
	<< std::setfill('0') << std::setw(2) << min
	<< std::setfill('0') << std::setw(2) << sec
	<< std::setfill('0') << std::setw(2) << "] ";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	if (deposit <= 0) {
		std::cout
		<< "index:" <<_accountIndex
		<< ";p_amount:" <<this->_amount
		<< ";deposit:refused"
		<< std::endl;
		return ;
	}
	else
	{
		std::cout
		<< "index:" << this->_accountIndex
		<< ";p_amount:" <<this->_amount;

		this->_nbDeposits += 1;
		this->_amount += deposit;
		_totalNbDeposits += 1;
		_totalAmount += deposit;

		std::cout
		<< ";deposit:" << deposit
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
	}
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (withdrawal <= 0 || withdrawal > this->_amount) {
		std::cout << "index:" <<_accountIndex
		<< ";p_amount:" << this->_amount
		<< ";withdrawal:refused"
		<< std::endl;
		return false ;
	}
	else
	{
		std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount;

		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;

		std::cout
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
		return true ;
	}

}

int	Account::checkAmount( void ) const
{
	return (this->_totalAmount);
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout
	<< "index:" << _accountIndex
	<< ";amount:" << _amount
	<< ";closed"
	<< std::endl;
}