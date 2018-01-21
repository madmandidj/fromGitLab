#include "BareketCards.h"
#include <iostream>

int main()
{
	size_t numOfPlayers = 4;
	
	BareketCards::SetDefaultNumOfPlayers(numOfPlayers);
	
	BareketCards brktCards;
	
	brktCards.Shuffle();
	
	brktCards.Deal();
	
	std::cout << std::endl << std::endl << "Welcome to Bareket Cards!" << std::endl << std::endl;
	
	brktCards.PrintScore(0);

	brktCards.PrintScore(1);
	
	brktCards.PrintScore(2);
	
	brktCards.PrintScore(3);
	
	brktCards.Pause();

	brktCards.Start();
	
	
	return 0;
}
