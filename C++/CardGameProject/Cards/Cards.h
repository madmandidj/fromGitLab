#ifndef __CARDS_H__
#define __CARDS_H__

#include "../Card/Card.h"
#include <stddef.h>
#include <vector>
#include <iostream>

class Cards
{
	public:
		Cards();
		
		~Cards();
		
		void 			Shuffle();
		
		void 			Sort();
		
		Card*			GetCard(size_t _index) const;
				
		bool 			RemoveCard(size_t _index);		
				
		bool			PushBackCard(const Card* _card);
		
		size_t			GetNumOfCards() const;
		
		void			PrintCards() const;
		
		void			SwapCards(Card* _card1, Card* _card2);
		
	private:
		Cards(Cards& _cards);
		
		Cards& operator= (Cards& _cards);
		
		std::vector<Card*> m_cards;
};



inline Cards::Cards()
{
	
}


inline Cards::~Cards()
{
	if (m_cards.size() > 0 )
	{
		/* TODO: loop and free all remaining cards ? */
	}
}


inline size_t Cards::GetNumOfCards() const
{
	return m_cards.size();
}


inline Card* Cards::GetCard(size_t _index) const
{
	if ((m_cards.size() < _index))
	{
		return 0;
	}
	
	return (Card*)m_cards.at(_index);
}


inline void Cards::PrintCards() const
{
	size_t index;
	size_t numOfCards = m_cards.size();
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


#endif /*#ifndef __CARDS_H__*/


