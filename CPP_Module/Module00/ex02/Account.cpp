/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaravan <acaravan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 05:21:20 by acaravan          #+#    #+#             */
/*   Updated: 2021/09/26 09:18:36 by acaravan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::makeDeposit( int deposit )
{
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (Account::checkAmount() >= withdrawal)
	{
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		return (true);
	}
	else
		return (false);
}

void	Account::displayAccountsInfos( void )
{
	std::cout << "Acc. Number: " << _nbAccounts << std::endl;
	std::cout << "Total Amount: " << _totalAmount << std::endl;
	std::cout << "Total Number of Deposits: " << _totalNbDeposits << std::endl;
	std::cout << "Total Number of Withdrawals: " << _totalNbWithdrawals << std::endl;
}

Account::Account ( int initial_deposit )
{
	static int count = 0;
	count++;
	_totalAmount = initial_deposit;
	_amount = initial_deposit;
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = count;
}

Account::~Account( void )
{
	
}

void	Account::displayStatus( void ) const
{
	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << "Acc. Index: " << _accountIndex << std::endl;
	std::cout << "Total Amount: " << _amount << std::endl;
	std::cout << "Total Number of Deposits: " << _nbDeposits << std::endl;
	std::cout << "Total Number of Withdrawals: " << _nbWithdrawals << std::endl;
}


