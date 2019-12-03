/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdeomin <bdeomin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:05:47 by bdeomin           #+#    #+#             */
/*   Updated: 2019/12/03 19:19:44 by bdeomin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"

#include <ctime>
#include <iostream>
#include <iomanip>

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0),
										_nbWithdrawals(0)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << \
	";created" << std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts--;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << \
	";closed" << std::endl;
}

int			Account::_nbAccounts = 0;
int			Account::_totalAmount = 0;
int			Account::_totalNbDeposits = 0;
int			Account::_totalNbWithdrawals = 0;

int			Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int			Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int			Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int			Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

void		Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << \
	Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << \
	";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void		Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
	";p_amount:" << this->_amount << ";deposit:" << deposit;

	this->_amount += deposit;
	this->_nbDeposits++;

	std::cout << ";amount:" << this->_amount << ";nb_deposit:" << \
	this->_nbDeposits << std::endl;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
}

bool		Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << \
	";p_amount:" << this->_amount << ";withdrawal:";

	if (this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	std::cout << withdrawal << ";amount" << this->_amount << \
	";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;

	return true;
}

int			Account::checkAmount(void) const
{
	return this->_amount;
}

void		Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << \
	";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << \
	std::endl;
}

void		Account::_displayTimestamp(void)
{
	time_t		time_val;
	tm			*time_ptr;

	time_val = time(NULL);
	time_ptr = localtime(&time_val);

	std::cout << "[" << time_ptr->tm_year + 1900 << std::setw(2) << std::right << \
	std::setfill('0') << time_ptr->tm_mon + 1 << std::setw(2) << std::right << \
	std::setfill('0') << time_ptr->tm_mday << "_" << std::setw(2) << std::right << \
	std::setfill('0') << time_ptr->tm_hour << std::setw(2) << std::right << \
	std::setfill('0') << time_ptr->tm_min << std::setw(2) << std::right << \
	std::setfill('0') << time_ptr->tm_sec << "] ";
}
