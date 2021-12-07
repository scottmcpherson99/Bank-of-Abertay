#pragma once
#include <string>
#include "Account.h"

class Customer
{
public:
	Customer();
	~Customer();

	std::string getName()const;
	void setName(std::string name_);

	int getBankID()const;
	void setBankID(int ID_);

	int getPasscode()const;
	void setPasscode(int passcode_);

	Account& GetAccount(int accountNumber);

	Account* accountPtr;
protected:

	Account account[5];
	std::string name;
	int bankID;
	int passcode;
};

