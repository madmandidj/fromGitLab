#include "Player.h"
#include "../Cards/Cards.h"
#include "../Card/Card.h"
#include <iostream>
#include <cstdlib>
#include <ctime>



int main()
{
	Cards hand1;
	Cards hand2;
	Cards deck;
	Cards board;
	
	
	
	size_t suitIndex;
	size_t valIndex;
	size_t deckIndex = 0;
	CardSuit cardSuit;
	const char SuitCharArr[] = {'C', 'D', 'H', 'S'};
	const char ValCharArr[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	Card* getCard;
	
	Card* getCard2;
	
	Card cards[52];
	
	srand(time(0));
	
	for(suitIndex = 0; suitIndex < numOfSuits; ++suitIndex)
	{
		for (valIndex = 0; valIndex < numOfVals; ++valIndex)
		{	
			cards[deckIndex].SetSuit(SuitCharArr[suitIndex]);
		
			cards[deckIndex].SetVal(ValCharArr[valIndex]);
			
			deck.PushBackCard(cards + deckIndex);
			
			++deckIndex; 
			
		}
	}
	
	deck.PrintCards();
	
	Player player(&deck, &board);
	
	player.ShowCards();
	
	player.TakeCard(&deck);
	
	deck.PrintCards();
	
	player.ShowCards();
	
	player.TakeCard(&deck);
	
	deck.PrintCards();
	
	player.ShowCards();
	
	return 0;
}
