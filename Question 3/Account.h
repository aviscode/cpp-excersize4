/*
File: Account.h
Description: This is the Account.h flie.
Course: 150018 C++ Workshop,
Exercise 4, Question 3
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include"mytypes.h"
#include<iostream>
using namespace std;


class Account {
private:
	uint _accountNumber;
	uint _code;
	float _balance;
	static uint _sumWithdraw;	//static uint for the class
	static uint _sumDeposit;	//static uint for the class
public:
	// constructor
	Account(uint accountNumber = 0, uint code = 0, int balance = 0);

	//operators
	friend istream& operator >>(istream&,  Account&);


	//public functions
	void withdraw(int);
	void deposit(float);

	//get and set the values for acccount.
	static uint const getSumWithdraw();
	static uint const getSumDeposit();
	int getAccountNumber()const;
	int getCode()const;
	int getBalance()const;
};

#endif //_ACCOUNT_H_