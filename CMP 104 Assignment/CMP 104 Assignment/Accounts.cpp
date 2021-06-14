#include "Accounts.h"

Accounts::Accounts()
{

}

Accounts::~Accounts()
{

}

//withdraw money from the account
void Accounts::withdraw(double transactionAmount_)
{
	balance -= transactionAmount_;
}

//deposit money into the account
void Accounts::deposit(double transactionAmount_)
{
	balance += transactionAmount_;
}


//calculae if a loan can be taken
bool Accounts::takeLoan(double loanAmount)
{
	if (loanAmount < balance * 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//calculate the interest on an account
double Accounts::interest(double interestAmount)
{
	return balance  *= interestAmount;
}

//set the balance of an account
void Accounts::setBalance(double balance_)
{
	balance = balance_;
}

//eturn the balance in the account
double Accounts::getBalance()
{
	return balance;
}
