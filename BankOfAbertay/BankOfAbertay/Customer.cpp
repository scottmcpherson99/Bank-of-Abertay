#include "Customer.h"

Customer::Customer():accountPtr(NULL), name("Unknown"), bankID(0), passcode(0)
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
std::string Customer::getName()const
{
	return name;
}


//set the customers bank id
void Customer::setBankID(int ID_)
{
	bankID = ID_;
}


//get the customers bank id
int Customer::getBankID()const
{
	return bankID;
}


//set the customers pin
void Customer::setPasscode(int passcode_)
{
	passcode = passcode_;
}

//get the customers pin
int Customer::getPasscode()const
{
	return passcode;
}

//return the customer account
Account& Customer::GetAccount(int accountNumber_)
{
	return account[accountNumber_];
}