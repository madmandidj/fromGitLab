#include "Card.h"
#include <iostream>





int main()
{
	Card card1;
	Card card2;
	
	card1.SetSuit('C');
	card1.SetVal('T');
	card2.SetSuit('H');
	card2.SetVal('3');
	
	std::cout << (card1 > card2) << std::endl;
	
	return 0;
}




