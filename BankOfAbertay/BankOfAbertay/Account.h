#pragma once
class Account
{
public:
	Account();
	~Account();

	float GetBalance()const;
	void Deposit(float amount);
	bool Withdraw(float amount);
	float CalculateInterest()const;
	bool CanTakeLoan(float amount)const;
	void SetOverdraftLimit(float limit);
protected:
	float balance;
	float overdraftLimit;
};

