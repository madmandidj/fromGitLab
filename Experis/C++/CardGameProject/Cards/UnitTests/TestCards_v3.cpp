#include "Cards.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int main()
{
	size_t index;
	CardSuit cardSuit;
	const char SuitCharArr[] = {'C', 'D', 'H', 'S'};
	const char ValCharArr[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
		
	srand(time(0));
	
//	Card card1;
//	Card card2;
//	Card card3;
//	Card card4;
	Card* getCard;
	Card* getCard2;
	
	Card cards[13];
	
	Cards hand1;
	Cards table;
	
//	card1.SetSuit('H');
//	card2.SetSuit('H');
//	card3.SetSuit('H');
	
	for (index = 0; index < numOfVals; ++index)
	{
		cards[index].SetSuit(SuitCharArr[index % numOfSuits]);
		
		cards[index].SetVal(ValCharArr[rand() % numOfVals]);
		
		hand1.PushBackCard(cards + index);
	}
	
	
//	card1.SetSuit('H');
//	
//	card1.SetVal('4');
//	card2.SetVal('8');
//	card3.SetVal('Q');
//	card4 = card1;
	
//	hand1.InsertCard(&card1);
//	hand1.InsertCard(&card2);
//	hand1.InsertCard(&card3);
//	hand1.InsertCard(&card4);
	
	hand1.PrintCards();
	
//	cout << ((card1 == card2) && (card2 >> card1)) << endl;
	
	hand1.Sort();
	
	
	hand1.PrintCards();
	
//	hand1.Shuffle();
//	
//	hand1.PrintCards();
//	
//	hand1.Shuffle();
//	
//	hand1.PrintCards();
//	
//	hand1.Shuffle();
//	
//	hand1.PrintCards();
//	
//	hand1.Shuffle();
//	
//	hand1.PrintCards();
	
	
	getCard = hand1.GetCard(2);
	
	hand1.RemoveCard(2);
	
	table.PushBackCard(getCard);
	
	getCard2 = table.GetCard(0);
	
	getCard = hand1.GetCard(1);
	
	
	return 0;
}



