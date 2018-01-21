#include "Cards.h"
#include <cstdlib> 	// rand()


/**********************
Public member functions
**********************/
bool Cards::RemoveCard(size_t _index)
{
	if (m_cardsVec.size() <= _index)
	{
		return false;
	}
	
	std::vector<Card*>::iterator it = m_cardsVec.begin();
	
	for (size_t index = 0; index < _index; ++index)
	{
		++it;
	}
	
	m_cardsVec.erase(it);
	
	return true;
}


bool Cards::InsertCard(const Card* _card, size_t _index)
{
	if (0 == _card || m_cardsVec.size() <= _index)
	{
		return false;
	}
	
	std::vector<Card*>::iterator it = m_cardsVec.begin();
	
	for (size_t index = 0; index < _index; ++index)
	{
		++it;
	}
	
	m_cardsVec.insert(it, (Card*)_card);
	
	return true;
}


bool Cards::PushBackCard(const Card* _card)
{	
	if (0 == _card)
	{
		return false;
	}	
	
	m_cardsVec.push_back((Card*)_card);
	
	return true;
}


void Cards::PrintCards() const
{
	size_t index;
	size_t numOfCards = m_cardsVec.size();
	Card* card;
	
	for (index = 0; index < numOfCards; ++index)
	{
		card = GetCard(index);
		card->PrintCard();
		std::cout <<"  ";
	}
	
	std::cout << std::endl;
	
	return;
}


void Cards::Shuffle()
{
	size_t index;
	size_t size = m_cardsVec.size();
	Card* card;
	
	for (index = 0; index < size * 2; ++index)
	{
		int shuffleIndex = rand() % size;

		card = GetCard(shuffleIndex);
		
		RemoveCard(shuffleIndex);
		
		PushBackCard(card);
	}
}


void Cards::Sort()
{
	size_t index;
	size_t size = m_cardsVec.size();
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
			
			/* Sort Suits */
			if (true == (*lCard > *rCard))
			{
				SwapCards(lCard, rCard);
				swapOccured = true;
			}	
			
			/* Sort Vals */
			if (true == (*lCard == *rCard) && (*lCard >> *rCard))
			{
				SwapCards(lCard, rCard);
				swapOccured = true;
			}
		}
		
		--size;
		
		isSorted = (false == swapOccured) ? true : false;
	}
}


/**********************
Private member functions
**********************/
void Cards::SwapCards(Card* _card1, Card* _card2)
{
	if(0 == _card1 || 0 == _card2)
	{
		/* TODO: Handle null pointer */
	}

	Card tempCard;
	
	tempCard = *_card1;
	
	*_card1 = *_card2;
	
	*_card2 = tempCard;
	
	return;
}

























