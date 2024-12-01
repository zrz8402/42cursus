/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:25:25 by ruzhang           #+#    #+#             */
/*   Updated: 2024/12/01 15:53:41 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_accountIndex = getNbAccounts();
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	Account::_nbAccounts++;
	Account::_totalAmount += _amount;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
	
}

Account::~Account( void )
{
	Account::_nbAccounts--;
	Account::_totalAmount -= _amount;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ){
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ){
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ){
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
	return Account::_totalNbWithdrawals;
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::_displayTimestamp( void )
{
	
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" \
				<< Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() \
				<< ";withdrawls:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() \
		<< ";deposits:" << _nbDeposits << ";withdrawls:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;

	_amount += deposit;
	_nbDeposits++;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	std::cout << ";deposit:" << deposit << ";amount:" << checkAmount() \
			<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;

	if (withdrawal > checkAmount())
	{
		std::cout << ";withdrawl:refused\n";
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	_displayTimestamp();
	std::cout << ";withdrawl:" << withdrawal << ";amount:" << checkAmount() \
				<< ";nb_withdrawls:" << _nbWithdrawals << std::endl;
	return true;
}
