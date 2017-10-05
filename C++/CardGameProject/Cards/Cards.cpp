#include "Cards.h"
#include <cstdlib>
#include <ctime>

bool Cards::PushBackCard(const Card* _card)
{	
	m_cards.push_back((Card*)_card);
	
	return true;
}


bool Cards::RemoveCard(size_t _index)
{
	if ((m_cards.size() < _index))
	{
		return false;
	}
	
	std::vector<Card*>::iterator it = m_cards.begin();
	
	for (size_t index = 0; index < _index; ++index)
	{
		++it;
	}
	
	m_cards.erase(it);
	
	return true;
}



void Cards::Shuffle()
{
	size_t index;
	size_t size = m_cards.size();
	Card* card;
	
	for (index = 0; index < size * 2; ++index)
	{
		int shuffleIndex = rand() % size;

		card = GetCard(shuffleIndex);
		
		RemoveCard(shuffleIndex);
		
		PushBackCard(card);
	}
}


void Cards::SwapCards(Card* _card1, Card* _card2)
{
	Card tempCard;
	
	tempCard = *_card1;
	
	*_card1 = *_card2;
	
	*_card2 = tempCard;
	
	return;
}


void Cards::Sort()
{
	size_t index;
	size_t size = m_cards.size();
	Card* lCard;
	Card* rCard;
	Card tempCard;
	bool isSorted = false;
	bool swapOccured = false;
	
	
	/* Bubble sort suits & vals */
	while (false == isSorted)
	{
		swapOccured = false;
		
		for (index = 0; index < size - 1; ++index)
		{
			lCard = GetCard(index);
			rCard = GetCard(index + 1);
			
			if (true == (*lCard > *rCard))
			{
				/* Sort Suits */
				SwapCards(lCard, rCard);
				swapOccured = true;
			}	
			
			if (true == (*lCard == *rCard) && (*lCard >> *rCard))
			{
				/* Sort Vals */
				SwapCards(lCard, rCard);
				swapOccured = true;
			}
		}
		
		--size;
		
		isSorted = (false == swapOccured) ? true : false;
	}
}





