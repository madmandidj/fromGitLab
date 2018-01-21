#include "./Bank/Bank.h"
#include <iostream>


int main()
{
	Bank* bank = Bank::CreateBank();
	bank->CreateAccount("Personal", 1000, "Eyal Alon", 250, bank);
	bank->CreateAccount("Personal", 1001, "Joe Alon", 300, bank);
	bank->CreateAccount("Personal", 1002, "John Alon", 350, bank);
	bank->CreateAccount("Stock", 1003, "Marcy Darcy", 400, bank);
	bank->Notify("Personal");
	cout << "meow" << endl;
	bank->Notify("Stock");
	return 0;
}




