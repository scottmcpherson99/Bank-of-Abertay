#include <iostream>
#include "Customer.h"

int enteredID = 0;
int customerSlot;
Customer* customerptr;
Customer customer[5];
int choice;

//Tell the user they have entered the wrong details
void WrongDetails()
{
	std::cout << "Those deails do not match." << std::endl;
}

//Check if the users ID and passcode matches
bool EnterID()
{
	int enteredPasscode;

	std::cout << "Welcome to the bank of Abertay!" << std::endl;
	std::cout << "Please enter your customer ID or enter -1 to exit." << std::endl;

	std::cin >> enteredID;

	//check if the ID the user has entered is a valid ID on the system
	for (int i = 0; i < 5; i++)
	{
		if (enteredID == customer[i].getBankID())
		{
			customerSlot = i;
			break;
		}
		else
		{
			customerSlot = -1;
		}
	}

	//check to see if the passcode the user has entered matches the correct passcode for the entered customerID
	if (customerSlot != -1)
	{
		std::cout << "Please enter the pin for your account." << std::endl;
		std::cin >> enteredPasscode;

		if (enteredPasscode == customer[customerSlot].getPasscode())
		{
			std::cout << "Hello " << customer[customerSlot].getName() << std::endl;
			return true;
		}
		else
		{
			WrongDetails();
			return false;
		}
	}
	else
	{
		WrongDetails();
		return false;
	}

}

int main()
{
	float money;
	bool isCustomerUsingAccount;

	customer[0].setName("Barry");
	customer[0].setBankID(1999);
	customer[0].setPasscode(2255);

	customer[1].setName("Lindsey");
	customer[1].setBankID(7);
	customer[1].setPasscode(77);

	customer[2].setName("Gary");
	customer[2].setBankID(3108);
	customer[2].setPasscode(7133);

	while (enteredID != -1)
	{
		if (EnterID() == true)
		{
			customerptr = &customer[customerSlot];
			std::cout << "Please select which account you would like to access (0-4)" << std::endl;
			std::cin >> customerSlot;
			
			isCustomerUsingAccount = true;
			while (isCustomerUsingAccount == true)
			{
				customerptr->accountPtr = &customerptr->GetAccount(customerSlot);

				std::cout << "What would you like to do today?" << std::endl;
				std::cout << "Press 1 to show the current balance." << std::endl;
				std::cout << "Press 2 to withdraw £10." << std::endl;
				std::cout << "Press 3 to withdraw money." << std::endl;
				std::cout << "Press 4 to deposit money." << std::endl;
				std::cout << "Press 5 to calulate the interest you could get on this account." << std::endl;
				std::cout << "Press 6 to check if you are eligible for a loan." << std::endl;
				std::cout << "Press 7 to change the overdraft limit." << std::endl;
				std::cout << "Press 8 to change account." << std::endl;
				std::cout << "Press 9 to leave." << std::endl;
				std::cin >> choice;

				switch (choice)
				{
					//show the user their balance
				case 1:
					std::cout << "Your balance is £" << customerptr->accountPtr->GetBalance() << std::endl;
					break;

					//withdraw £10 from the users account
				case 2:
					if (customerptr->accountPtr->Withdraw(10) == true)
					{
						std::cout << "Here is your £10. Your new balance is £" << customerptr->accountPtr->GetBalance() << std::endl;
					}
					else
					{
						std::cout << "You have insufficent funds." << std::endl;
					}
					break;

					//allow the user to withdraw money from their account
				case 3:
					std::cout << "How much would you like to withdraw?" << std::endl;
					std::cin >> money;

					if (customerptr->accountPtr->Withdraw(money) == true)
					{
						std::cout << "Here is your " << money << ". Your new balance is £" << customerptr->accountPtr->GetBalance() << std::endl;
					}
					else
					{
						std::cout << "You have insufficent funds." << std::endl;
					}
					break;

					//allow the user to deposit money into their account
				case 4:
					std::cout << "How much would you like to deposit?" << std::endl;
					std::cin >> money;

					customerptr->accountPtr->Deposit(money);
					break;

					//calculate the interest the user could get on their account
				case 5:
					std::cout << "The interest you could get on your account is £" << customerptr->accountPtr->CalculateInterest() << std::endl;
					break;

					//let the user check if they are eligible for a loan
				case 6:
					std::cout << "How much would you like to loan?" << std::endl;
					std::cin >> money;
					if (customerptr->accountPtr->CanTakeLoan(money) == true)
					{
						std::cout << "You would be eligible for a loan of £" << money << std::endl;
					}
					else if (customerptr->accountPtr->CanTakeLoan(money) == false)
					{
						std::cout << "You would not be eligible for a loan of £" << money << std::endl;
					}
					break;

					//set the overdraft limit
				case 7:
					std::cout << "Enter the overdraft limit." << std::endl;
					std::cin >> money;
					customerptr->accountPtr->SetOverdraftLimit(money);
					break;

					//let the customer change accounts
				case 8:
					std::cout << "Which account would you like to use" << std::endl;
					std::cin >> customerSlot;
					break;

					//let the user sign off
				case 9:
					isCustomerUsingAccount = false;
					break;
				}
			}
		}
	}
}