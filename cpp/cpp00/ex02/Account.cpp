/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 17:25:25 by ruzhang           #+#    #+#             */
/*   Updated: 2024/12/04 12:00:36 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

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

/*
struct tm {
    int tm_sec;   // Seconds (0 to 59)
    int tm_min;   // Minutes (0 to 59)
    int tm_hour;  // Hours (0 to 23)
    int tm_mday;  // Day of the month (1 to 31)
    int tm_mon;   // Month (0 to 11; January is 0)
    int tm_year;  // Year since 1900 (e.g., 2024 would be 124)
    int tm_wday;  // Day of the week (0 to 6; Sunday is 0)
    int tm_yday;  // Day of the year (0 to 365)
    int tm_isdst; // Daylight saving time flag (positive if DST, 0 if not, negative if unknown)
};
*/
void	Account::_displayTimestamp( void )
{
	time_t	timestamp = time(NULL);
	tm * tm = localtime(&timestamp);

	std::cout << "[" << (tm->tm_year + 1900);
	std::cout << std::setfill('0') << std::setw(2) << (tm->tm_mon + 1);
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << tm->tm_sec << "] ";
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";total:" \
				<< Account::getTotalAmount() << ";deposits:" << Account::getNbDeposits() \
				<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() \
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
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
		std::cout << ";withdrawal:refused\n";
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal << ";amount:" << checkAmount() \
				<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}
