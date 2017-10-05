#include "Cards.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
		
	srand(time(0));
	
	Card card1;
	Card card2;
	Card card3;
	Card card4;
	Card* getCard;
	Card* getCard2;
	
	Cards hand1;
	Cards table;
	
	card1.SetSuit('H');
	card2.SetSuit('H');
	card3.SetSuit('H');
	
	card1.SetVal('4');
	card2.SetVal('8');
	card3.SetVal('Q');
	card4 = card1;
	
	hand1.InsertCard(&card1);
	hand1.InsertCard(&card2);
	hand1.InsertCard(&card3);
	hand1.InsertCard(&card4);
	
	
	cout << ((card1 == card2) && (card2 >> card1)) << endl;
	
	hand1.Sort();
	
	
	hand1.PrintCards();
	
	hand1.Shuffle();
	
	hand1.PrintCards();
	
	hand1.Shuffle();
	
	hand1.PrintCards();
	
	hand1.Shuffle();
	
	hand1.PrintCards();
	
	hand1.Shuffle();
	
	hand1.PrintCards();
	
	
	getCard = hand1.GetCard(2);
	
	hand1.RemoveCard(2);
	
	table.InsertCard(getCard);
	
	getCard2 = table.GetCard(0);
	
	getCard = hand1.GetCard(1);
	
	
	return 0;
}



