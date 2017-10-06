#include "BareketCards.h"
#include <iostream>



int main()
{
	BareketCards brktCards;
	
	brktCards.Shuffle();
	
	brktCards.Deal();
	
	brktCards.PrintScore(0);

	brktCards.PrintScore(1);
	
	brktCards.PrintScore(2);
	
	brktCards.PrintScore(3);
	
	brktCards.Pause();

	brktCards.Start();
	
	
	return 0;
}
