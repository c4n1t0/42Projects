/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaromero <jaromero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 01:37:58 by jaromero          #+#    #+#             */
/*   Updated: 2023/01/27 01:46:01 by jaromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

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

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
                << ";total:" << getTotalAmount()
                << ";deposits:" << getNbDeposits()
                << ";withdrawal:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
{
    _displayTimestamp();
    _amount += initial_deposit;
    _totalAmount = _totalAmount + initial_deposit;
    _nbAccounts++;
    _accountIndex = _nbAccounts - 1;
    std::cout << "index:" << getNbAccounts() - 1 << ";amount:"
                << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"
                << _amount << ";closed" << std::endl;
    _nbAccounts--;
    _amount = 0;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
                << ";deposit:" << deposit << ";amount:";
    _totalAmount -= _amount;
    _amount += deposit;
    _totalAmount += _amount;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << _amount << ";nb_deposit:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
                << ";withdrawal:";
    if (withdrawal > checkAmount())
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    _nbWithdrawals++;
    _totalAmount -= _amount;
    _amount -= withdrawal;
    _totalAmount += _amount;
    _totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << _amount << ";nb_deposit:"
                << _nbDeposits << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" 
                << _amount << ";deposits:" << _nbDeposits
                << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
    std::time_t date = std::time(0);

    tm *time = localtime(&date);
    std::cout << "[" << 1900 + time->tm_year;
    if (time->tm_mon < 9)
        std::cout << "0" << time->tm_mon + 1;
    else
        std::cout << time->tm_mon + 1;
    if (time->tm_mday < 10)
        std::cout << "0" << time->tm_mday;
    else
        std::cout << time->tm_mday; 
    std::cout << "_";
    if (time->tm_hour < 10)
        std::cout << "0" << time->tm_hour;
    else
        std::cout << time->tm_hour;
    if (time->tm_min < 10)
        std::cout << "0" << time->tm_min;
    else
        std::cout << time->tm_min;
    if (time->tm_sec < 10)
        std::cout << "0" << time->tm_sec;
    else
        std::cout << time->tm_sec;
    std::cout << "] ";
}
