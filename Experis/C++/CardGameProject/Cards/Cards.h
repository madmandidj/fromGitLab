#ifndef __CARDS_H__
#define __CARDS_H__

#include "../Card/Card.h"
#include <vector>	
#include <iostream>	//size_t, cout, endl

class Cards
{
	public:
		Cards();
		
		~Cards();
		
		Card*			GetCard(size_t _index) const;
				
		bool 			RemoveCard(size_t _index);
		
		bool			InsertCard(const Card* _card, size_t _index);	
				
		bool			PushBackCard(const Card* _card);
		
		size_t			GetNumOfCards() const;
		
		void			PrintCards() const;
		
		void 			Shuffle();
		
		void 			Sort();
		
	private:
		Cards(Cards& _cards);
		
		Cards& operator= (Cards& _cards);
		
		void SwapCards(Card* _card1, Card* _card2); /*Note: Swaps values, not elements!*/
		
	private:
		std::vector<Card*> m_cardsVec;
};


/***************
inline functions
****************/
inline Cards::Cards(){}


inline Cards::~Cards(){}


inline Card* Cards::GetCard(size_t _index) const
{
	return (m_cardsVec.size() > _index) ? (Card*)m_cardsVec.at(_index) : 0;
}


inline size_t Cards::GetNumOfCards() const
{
	return m_cardsVec.size();
}


#endif /*#ifndef __CARDS_H__*/






















