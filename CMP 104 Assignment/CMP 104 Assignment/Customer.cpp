#include "Customer.h"

Customer::Customer()
{
	cout << "A customer has been created!" << endl;
}

Customer::~Customer()
{
	cout << "A customer has been removed." << endl;
}

//set or change the customers name
void Customer::setName(string name_)
{
	name = name_;
}

//get the customers name
string Customer::getName()
{
	return name;
}


//set the customers ID
void Customer::setCustomerID(unsigned short int customerID_)
{
	customerID = customerID_;
}

//get the customers ID
unsigned short int Customer::getCustomerID()
{
	return customerID;
}


//set or change the customers pin number
void Customer::setPinNumber(int pinNumber_)
{
	pinNumber = pinNumber_;
}

//get the customers pin number
int Customer::getPinNumber()
{
	return pinNumber;
}


//get the customers account
Accounts Customer::getAccount(unsigned short int accountNumber_)
{
	return account[accountNumber_];
}


//activate the customes initial accounts
void Customer::ActivateInitialAccounts()
{
	accountActive[0] = true;

	for (int i = 1; i < 5; i++)
	{
		accountActive[i] = false;
	}
}

//check if account is active
bool Customer::IsAccountActive(int accountNumber_)
{
	return accountActive[accountNumber_];
}

//activate a new account
void Customer::ActivateAccount()
{
	for (int i = 0; i < 5; i++)
	{
		if (accountActive[i] != true)
		{
			accountActive[i] = true;
			cout << "Account created!" << endl;
			return;
		}
	}
	cout << "Max accounts created." << endl;
}