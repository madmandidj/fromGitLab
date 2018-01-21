#include "Players.h"
#include "../Player/Player.h"
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
	
	Players players(&deck, &board);
	
	players[0]->TakeCard(players.m_deck);
	
	players[3]->TakeCard(players.m_deck);
	
	players[0]->ShowCards();
	
	players[3]->ShowCards();

	return 0;
}
