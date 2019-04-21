/*
File: Account.cpp
Description: This is the Account.cpp flie.
Course: 150018 C++ Workshop,
Exercise 4, Question 3
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#include "Account.h"


//static variable first reset to 0.
uint Account::_sumWithdraw = 0;
uint Account::_sumDeposit = 0;

//constractor
Account::Account(uint accountNumber, uint code, int balance) {
	_accountNumber = accountNumber;
	_code = code;
	_balance = balance;
}


//operators
istream& operator >>(istream& in,  Account& bank) {
	cout << "enter account number:";
	in >> bank._accountNumber;
	cout << "enter code:";
	in >> bank._code;
	return in;
}

//public functions
void Account::withdraw(int nis) {
	if (nis > 2500)throw "ERROR: cannot withdraw more than 2500 NIS!\n";
	if (nis - _balance < -6000)throw "ERROR: cannot have less than - 6000 NIS!\n";
	_balance -= nis;
	_sumWithdraw += nis;
}

void Account::deposit(float checks) {
	if (checks > 10000)throw "ERROR: cannot deposit more than 10000 NIS!\n";
	_balance += checks;
	_sumDeposit += checks;
}

uint const Account::getSumWithdraw() {
	return _sumWithdraw;
}

uint const Account::getSumDeposit() {
	return _sumDeposit;
}

int Account::getAccountNumber()const {
	return _accountNumber;
}

int Account::getCode()const {
	return _code;
}

int Account::getBalance()const {
	return _balance;
}