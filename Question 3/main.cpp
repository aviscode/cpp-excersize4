/*
File: main.cpp
Description: This is the main file of the program.
Course: 150018 C++ Workshop,
Exercise 4, Question 3
Author: Avrumi Rosenberg ID:208509653 == zevi abramovich id 313583460
*/

#include <iostream>
#include "Clock.h"
#include "account.h"

using namespace std;


//enum options
enum Action {
	STOP,
	BALANCE,
	DEPOSIT,
	WITHDRAW,
	SUM_WITHDRAW,
	SUM_DEPOSIT
};

//enum options text.
Action menu() {
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (Action)x;
}

//find account function
int findAccount(Account* bank, int size) {
	uint number, code;
	cout << "please enter account number: ";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number) i++; //finding the account in the arrary of the accounts.
	if (i == size)throw "ERROR: no such account number!\n";		//if the acount was not find.		
	cout << "please enter the code: ";
	cin >> code;
	if (bank[i].getCode() == code) return i;	//checking the code if it maches.
	else
		throw "ERROR: wrong code!\n";		//throwing a error if the code is worng.
}


//print function for all optiont in the porgram to print.
void printTransaction(Account a, Action ac, Clock &c) {
	cout << c << "\t";
	switch (ac) {
	case BALANCE:
		cout << "Account #: " << a.getAccountNumber() << "\t";
		cout << "balance: " << a.getBalance() << endl;
		break;
	case DEPOSIT:
		cout << "Account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case WITHDRAW:
		cout << "Account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case SUM_DEPOSIT:
		cout << "Sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case SUM_WITHDRAW:
		cout << "Sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}

//gets the balaens of the account (and adding 30 sec to the clock)
void getBalance(Account* bank, int size, Clock &c) {
	c += 20;
	printTransaction(bank[findAccount(bank, size)], BALANCE, c);
}

//cashDeposit function that handels the deposeit to the account.
void cashDeposit(Account* bank, int size, Clock c) {
	int i = findAccount(bank, size);
	float amount;
	cout << "enter the amount of the check: ";
	cin >> amount;
	bank[i].deposit(amount);
	printTransaction(bank[i], DEPOSIT, c);
}

//cashWithdraw function that handels the withdraw from the account.
void cashWithdraw(Account* bank, int size, Clock c) {
	int i = findAccount(bank, size);
	c += 50;
	float amount;
	cout << "enter the amount of money to withdraw: ";
	cin >> amount;
	bank[i].withdraw(amount);
	printTransaction(bank[i], WITHDRAW, c);
}


// Function main - this is the entry code for the program
int main() {
	Clock clock(8);
	Account bank[10];

	//gets 10 account info 
	cout << "enter account number and code for 10 accounts:\n";
	for (int i = 0; i < 10; i++) {
		try {
			cin >> bank[i];
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())	//checking if the account number exist
					throw "ERROR: account number must be unique!\n";
			if (bank[i].getCode() < 999 || bank[i].getCode() > 9999) // checking the code is 4 digits and that the first digite is not 0.
				throw "ERROR: code must be of 4 digits and first digit cano't be 0 !\n";
		}
		catch (const char* msg) {
			cout << clock << '\t' << msg;
			i--;
		}
	}

	Action ac = menu();
	while (ac) {
		switch (ac) {
		case BALANCE:
			try {
				getBalance(bank, 10, clock);
			}
			catch (const char* msg) {
				cout << clock << '\t' << msg;
			}
			break;
		case DEPOSIT:
			try {
				clock += 30;
				cashDeposit(bank, 10, clock++);
			}
			catch (const char* msg) {
				cout << clock << '\t' << msg;
			}
			break;
		case WITHDRAW:
			try {
				cashWithdraw(bank, 10, ++clock);
			}
			catch (const char* msg) {
				cout << clock << '\t' << msg;
			}
			break;
		case SUM_WITHDRAW:
			clock += 60;
			printTransaction(bank[0], SUM_WITHDRAW, clock);
			break;
		case SUM_DEPOSIT:
			clock += 60;
			printTransaction(bank[0], SUM_DEPOSIT, clock);
			break;
		}
		ac = menu();
	}
	system("pause");
	return 0;
}
