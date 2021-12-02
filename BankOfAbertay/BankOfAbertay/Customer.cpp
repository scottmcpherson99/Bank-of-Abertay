#include "Customer.h"

Customer::Customer()
{

}

Customer::~Customer()
{

}

//set the customers name
void Customer::setName(std::string name_)
{
	name = name_;
}

//return the customers name
std::string Customer::getName()
{
	return name;
}


//set the customers bank id
void Customer::setBankID(int ID_)
{
	bankID = ID_;
}


//get the customers bank id
int Customer::getBankID()
{
	return bankID;
}


//set the customers pin
void Customer::setPasscode(int passcode_)
{
	passcode = passcode_;
}

//get the customers pin
int Customer::getPasscode()
{
	return passcode;
}

//return the customer account
Account& Customer::GetAccount(int accountNumber_)
{
	return account[accountNumber_];
}