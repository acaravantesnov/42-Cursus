#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	_nbAccounts++;
	t::_accountIndex = _nbAccounts - 1;
	t::_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << t::_accountIndex << ";amount:" << t::_amount << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << t::_accountIndex << ";amount:" << t::_amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << t::_accountIndex << ";p_amount:" << t::_amount;
	t::_amount += deposit;
	t::_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << t::_amount << ";nb_deposits:" << t::_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << t::_accountIndex << ";p_amount:" << t::_amount;
	if (t::_amount >= withdrawal)
	{
		t::_amount -= withdrawal;
		t::_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal << ";amount:" << t::_amount << ";nb_withdrawals:" << t::_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << t::_accountIndex << ";amount:" << t::_amount << ";deposits:" << t::_nbDeposits << ";withdrawals:" << t::_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(0);
	tm	*time = localtime(&now);
	std::cout << '[' << 1900 + time->tm_year;
	if (time->tm_mon <= 9)
		std::cout << "0";
	std::cout << time->tm_mon + 1;
	if (time->tm_mday <= 9)
		std::cout << "0";
	std::cout << time->tm_mday;
	std::cout << "_";
	if (time->tm_hour <= 9)
		std::cout << "0";
	std::cout << time->tm_hour;
	if (time->tm_min <= 9)
		std::cout << "0";
	std::cout << time->tm_min;
	if (time->tm_sec <= 9)
		std::cout << "0";
	std::cout << time->tm_sec << "] ";
}

