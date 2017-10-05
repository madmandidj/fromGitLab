#include "Cards.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
		
	srand(time(0));
	
	int randomNum = rand() % 10 + 1;
	
	cout << randomNum << endl;
	
	Card card1;
	Card card2;
	Card card3;
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
	
	hand1.InsertCard(&card1);
	hand1.InsertCard(&card2);
	hand1.InsertCard(&card3);
	
	hand1.PrintCards();
	
	cout << hand1.GetNumOfCards() << endl;
	
	getCard = hand1.GetCard(2);
	
	hand1.RemoveCard(2);
	
	cout << hand1.GetNumOfCards() << endl;
	
	getCard->PrintCard();
	
	table.InsertCard(getCard);
	
	getCard2 = table.GetCard(0);
	
	getCard2->PrintCard();
	
	cout << table.GetNumOfCards() << endl;
	
	getCard = hand1.GetCard(1);
	
	cout << (getCard < getCard2) << endl;
	
	
	return 0;
}



