#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::displayAccountsInfos( void )
{
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	_nbAccounts++;
	t::_accountIndex = _nbAccounts - 1;
	t::_amount = initial_deposit;
	_totalAmount += initial_deposit;
	std::cout << "index:" << t::_accountIndex << ";amount:" << t::_amount << ";created" << std::endl;
}

Account::~Account( void )
{
	std::cout << "index:" << t::_accountIndex << ";amount:" << t::_amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	std::cout << "index:" << t::_accountIndex << ";p_amount:" << t::_amount;
	t::_amount += deposit;
	t::_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << t::_amount << ";nb_deposits:" << t::_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
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
	std::cout << "index:" << t::_accountIndex << ";amount:" << t::_amount << ";deposits:" << t::_nbDeposits << ";withdrawals:" << t::_nbWithdrawals << std::endl;
}

