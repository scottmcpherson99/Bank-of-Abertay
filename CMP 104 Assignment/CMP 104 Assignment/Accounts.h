#pragma once
#include <string>

using namespace std;

class Accounts
{
public:
	Accounts();
	~Accounts();

	void withdraw(double transactionAmount);
	void deposit(double transactionAmount);
	bool takeLoan(double loanAmount);
	double interest(double interestAmount);
	void setBalance(double balance);
	double getBalance();

private:
	double balance;
	string customer;
};

