#include "Account.h"

Account::Account()
{
	balance = 0;
	overdraftLimit = 0;
}

Account::~Account()
{

}

//return the accounts balance
float Account::GetBalance()const
{
	return balance;
}


//withdraw money from the account
bool Account::Withdraw(float amount)
{
	if (balance - amount > overdraftLimit)
	{
		balance -= amount;
		return true;
	}
	else
	{
		return false;
	}
}


//deposit money into the account
void Account::Deposit(float amount)
{
	balance += amount;
}


//Calculate the interest the account coul get
float Account::CalculateInterest()const
{
	return balance * 0.1;
}


//Check if the customer can take a loan out
bool Account::CanTakeLoan(float loanAmount_)const
{
	if (loanAmount_ < balance * 2)
	{
		return true;
	}

	else
	{
		return false;
	}
}


//set the overdraftlimit
void Account::SetOverdraftLimit(float limit)
{
	overdraftLimit = -limit;
}