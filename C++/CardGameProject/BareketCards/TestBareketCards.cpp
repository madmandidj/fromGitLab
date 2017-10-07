#include "BareketCards.h"
#include <iostream>

int main()
{
	size_t numOfPlayers = 4;
	BareketCards::SetDefaultNumOfPlayers(numOfPlayers);
	BareketCards brktCards;
	bool quitFlag = false;
	bool readyForGame = false;
	int option;
	
	
	
	while(false == quitFlag)
	{
		std::cout << "Select an option: " << std::endl;
		std::cout << "1 - Shuffle" << std::endl;
		std::cout << "2 - Deal" << std::endl;
		std::cout << "3 - Start" << std::endl;
		std::cout << "4 - Set Round-By-Round On" << std::endl;
		std::cout << "5 - Set Round-By-Round Off" << std::endl;
		std::cout << "0 - Quit" << std::endl << std::endl;
		
		std::cin >>option;
		
		switch (option)
		{
			case 1:
				brktCards.Shuffle();
				
				std::cout << "Deck shuffled:" << std::endl;
				
				brktCards.ShowDeck();
				
				std::cout << std::endl;
				
				break;
			
			case 2:
				brktCards.Deal();
				
				std::cout << std::endl << std::endl << "Welcome to Bareket Cards! Here are the starting hands:" << std::endl;
				
				brktCards.PrintScore(0);

				brktCards.PrintScore(1);
	
				brktCards.PrintScore(2);
	
				brktCards.PrintScore(3);
				
				std::cout << std::endl;
				
				readyForGame = true;
				
				break;
			
			case 3:
				if (false == readyForGame)
				{
					std::cout << "Please Deal Cards before starting game" << std::endl << std::endl;
				}
				else
				{
					brktCards.Start();
				
					readyForGame = false;
				}
				
				break;
				
			case 4:
				brktCards.SetPrintMode(true);
				
				break;
				
			case 5:
				brktCards.SetPrintMode(false);	
						
				break;
				
			case 0:
				brktCards.Quit();
				quitFlag = true;
				break;
				
			default:
				break;
		}
	}
	
	return 0;
}
