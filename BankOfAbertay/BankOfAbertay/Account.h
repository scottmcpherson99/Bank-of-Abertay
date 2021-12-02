#pragma once
class Account
{
public:
	Account();
	~Account();

	float GetBalance();
	void Deposit(float amount);
	bool Withdraw(float amount);
	float CalculateInterest();
	bool CanTakeLoan(float amount);
	void SetOverdraftLimit(float limit);
protected:
	float balance;
	float overdraftLimit;
};

