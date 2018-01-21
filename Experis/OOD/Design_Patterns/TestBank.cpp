#include "./Bank/Bank.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	bool cont = true;
	int actionOption;
	int accountOption;
	unsigned int ID;
	string accountType;
	int accountID = 1;
	Bank* bank = Bank::CreateBank();
	
	while(true == cont)
	{
		cout << "Select an option" << endl;
		cout << "1 - Create Account" << endl;
		cout << "2 - Remove Account" << endl;
		cout << "3 - Summon all personal account owners" << endl;
		cout << "4 - Give bonus to all family accounts" << endl;
		cout << "5 - Invest in stock accounts" << endl;
		cout << "0 - Quit" << endl;
		cin >> actionOption;
		
		switch (actionOption)
		{
			case 1:
				cout << "Select Account Type to Create" << endl;
				cout << "1 - Personal" << endl;
				cout << "2 - Family" << endl;
				cout << "3 - Stock" << endl;
				cin >> accountOption;
				switch (accountOption)
				{
					case 1:
						accountType = "Personal";
						break;
		
					case 2:
						accountType = "Family";
						break;
			
					case 3:
						accountType = "Stock";
						break;
				}
				bank->CreateAccount(accountType, accountID, "Eyal Alon", 250, bank);
				++accountID;
				break;
				
			case 2:
				cout << "Select Account Type to Remove" << endl;
				cout << "1 - Personal" << endl;
				cout << "2 - Family" << endl;
				cout << "3 - Stock" << endl;
				cin >> accountOption;
				switch (accountOption)
				{
					case 1:
						accountType = "Personal";
						break;
		
					case 2:
						accountType = "Family";
						break;
			
					case 3:
						accountType = "Stock";
						break;
				}
				cout << "Enter account ID to remove" << endl;
				cin >> ID;
				bank->RemoveAccount(accountType, ID);
				break;
				
			case 3:
				bank->SummonPersonalAccountOwners();
				break;
				
			case 4:
				bank->GiveBonusToFamilyAccounts();
				break;
				
			case 5:
				bank->InvestInStockAccounts();
				break;
				
			case 0:
				cont = false;
				break;
		}
		cout << endl;
	}
	
	return 0;
}




