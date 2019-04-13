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
	static uint _sumWithdraw;
	static uint _sumDeposit;
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