#include <iostream>
#include "Customer.h"
#include "Accounts.h"

using namespace std;


int main()
{
	short int customerID = 0;
	short int userInput = 0;
	short int transactionAmount = 0;
	int enteredPin = 0;
	int accountNumber = 0;

	Customer customer[5];

	customer[0].setName("Bob");
	
	customer[0].setCustomerID(0);
	customer[0].getAccount(0).setBalance(10);
	customer[0].setPinNumber(1111);

	customer[1].setName("Sandy");
	customer[1].setCustomerID(1);
	customer[1].getAccount(0).setBalance(69);
	customer[1].setPinNumber(2222);

	customer[2].setName("Salma");
	customer[2].setCustomerID(2);
	customer[2].getAccount(0).setBalance(100000);
	customer[2].setPinNumber(3333);

	for (int i = 0; i < 3; i++)
	{
		customer[i].ActivateInitialAccounts();
	}

	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			customer[j].getAccount(i).setBalance(0);
		}
	}
	
	while (customerID != -1)
	{
		cout << "Please enter your customer ID or enter -1 to exit." << endl;
		cin >> customerID;

		if (customerID != -1)
		{
			userInput = 0;
		}

		while (userInput != -1)
		{
			cout << "Please enter your pin number." << endl;
			cin >> enteredPin;

			if (enteredPin == customer[customerID].getPinNumber())
			{

				cout << "Please enter your account number." << endl;
				cin >> accountNumber;

				if (customer[customerID].IsAccountActive(accountNumber) == true)
				{
					cout << "Hi " << customer[customerID].getName() << ". What would you like to do today?" << endl;
					cout << "To Check your balance press 0." << endl << "To deposit cash press 1." << endl << "To withdraw money press 2." << endl << "To calculate your interest press 3." << endl << "To check if you are available for a loan press 4." << endl << "To make a quick withdraw of £10 press 5." << endl << "To activate a new account press 6." << endl << "To exit press -1." << endl;
					cin >> userInput;

					switch (userInput)
					{
						//Check users balance
					case 0:
						cout << "Your balance is " << customer[customerID].getAccount(0).getBalance() << endl;
						break;

						//Deposit Cash
					case 1:
						cout << "How much would you like to deposit?" << endl;
						cin >> transactionAmount;

						customer[customerID].getAccount(0).deposit(transactionAmount);

						cout << "Your new balance is " << customer[customerID].getAccount(0).getBalance() << endl;
						break;

						//Withdraw Cash
					case 2:
						cout << "How much would you like to withdraw?" << endl;
						cin >> transactionAmount;

						if (customer[customerID].getAccount(0).getBalance() - transactionAmount >= 0)
						{
							customer[customerID].getAccount(0).withdraw(transactionAmount);

							cout << "Your new balance is " << customer[customerID].getAccount(0).getBalance() << endl;
						}
						else
						{
							cout << "You do not have the funds for that!" << endl;
						}
						break;

						//Calculate Interest
					case 3:
						cout << "Your balance after interest would be " << customer[customerID].getAccount(0).interest(1.01) << endl;
						break;

						//Check if a loan can be taken
					case 4:
						cout << "Please enter the amount you would like to loan." << endl;
						cin >> transactionAmount;

						if (customer[customerID].getAccount(0).takeLoan(transactionAmount) == true)
						{
							cout << "The loan can be granted." << endl;
						}
						else
						{
							cout << "The loan can not be granted." << endl;
						}
						break;

						//Quick withdraw of £10
					case 5:
						if (customer[customerID].getAccount(0).getBalance() - 10 >= 0)
						{
							customer[customerID].getAccount(0).withdraw(10);

							cout << "Your new balance is " << customer[customerID].getAccount(0).getBalance() << endl;
						}
						else
						{
							cout << "You do not have the funds for that!" << endl;
						}
						break;

						//activate a new account
					case 6:
						customer[customerID].ActivateAccount();
					}
				}
				else
				{
					cout << "That account is not active." << endl;
				}
			}
			else
			{
				cout << "Invalid Pin." << endl;
				userInput = -1;
			}
			
		}
	}
	return 0;
}
