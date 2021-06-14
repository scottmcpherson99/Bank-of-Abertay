#pragma once
#include <iostream>
#include <string>
#include "Accounts.h"

using namespace std;

class Customer
{
public:
	Customer();
	~Customer();

	void setName(string name_);
	string getName();
	void setCustomerID(unsigned short int customerID_);
	unsigned short int getCustomerID();
	void setPinNumber(int pinNumber_);
	int getPinNumber();
	Accounts getAccount(unsigned short int accountNumber_);
	void ActivateInitialAccounts();
	bool IsAccountActive(int accountNumber_);
	void ActivateAccount();

private:
	string name;
	unsigned short int customerID;
	Accounts account[5];
	bool accountActive[5];
	int pinNumber;
};

