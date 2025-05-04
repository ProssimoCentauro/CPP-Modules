#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void )
{
	std::time_t t = std::time(NULL);
    std::tm* now = std::localtime(&t);
    
    std::cout << '['
              << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << now->tm_mon + 1
              << std::setw(2) << std::setfill('0') << now->tm_mday
              << '_'
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec
              << "] ";
	
	//more immediate method
	//std::strftime(time, sizeof(time), "%Y%m%d_%H%M%S", tm*);
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;


	_displayTimestamp();
	std::cout << "index:"  << _accountIndex << ";";
	std::cout << "amount:"  << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:"  << _accountIndex << ";";
	std::cout << "amount:"  << _amount << ";";
	std::cout << "closed" << std::endl;
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

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:"  << _accountIndex << ";";
	std::cout << "amount:"  << _amount << ";";
	std::cout << "deposits:"  << _nbDeposits << ";";
	std::cout << "withdrawals:"  << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:"  << _nbAccounts << ";";
	std::cout << "total:"  << _totalAmount << ";";
	std::cout << "deposits:"  << _totalNbDeposits << ";";
	std::cout << "withdrawals:"  << _totalNbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
	
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount - deposit
				<< ";deposit:" << deposit
				<< ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount;
	
	if (withdrawal > this->_amount)
	{
		std::cout << ";refused" << std::endl;
		return (false);
	}
	
	std::cout	<< ";withdrawal:" << withdrawal
				<< ";amount:" << this->_amount - withdrawal
				<< ";nb_withdrawals:" << this->_nbWithdrawals + 1
				<< std::endl;

	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	return (true);
}
