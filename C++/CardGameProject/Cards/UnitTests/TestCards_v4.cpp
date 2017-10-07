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
	Card* getCard;
	Card* getCard2;
	Card cards[13];
	Cards hand1;
	Cards table;
	
	srand(time(0));
	
	for (index = 0; index < numOfVals; ++index)
	{
		cards[index].SetSuit(SuitCharArr[index % numOfSuits]);
		
		cards[index].SetVal(ValCharArr[rand() % numOfVals]);
		
		hand1.PushBackCard(cards + index);
	}
	
	hand1.PrintCards();
	
	hand1.Shuffle();
	
	hand1.PrintCards();
	
	hand1.Shuffle();
	
	hand1.PrintCards();
	
	hand1.Shuffle();
	
	hand1.PrintCards();
	
	hand1.Shuffle();
	
	hand1.PrintCards();
	
	hand1.Shuffle();
	
	hand1.Sort();
	
	hand1.PrintCards();
	

	
	
	return 0;
}



