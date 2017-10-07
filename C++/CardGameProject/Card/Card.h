#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>	//size_t, cout, endl

const size_t NUM_OF_SUITS = 4;
const size_t NUM_OF_VALS = 13;

const char SUIT_CHAR_ARR[] = {'C', 'D', 'H', 'S'}; /* TODO: Ask about this. Could be moved to BareketCards.cpp */
const char VAL_CHAR_ARR[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'}; /* TODO: Ask about this. Could be moved to BareketCards.cpp */


typedef enum CardSuit
{
	Clubs = 0,
	Diamonds,
	Hearts,
	Spades
}CardSuit;

typedef enum CardVal
{
	Two = 0,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace
}CardVal;


class Card
{
	public:
		Card();
		
		~Card();
		
		Card& operator= (const Card& _card);
		
		void SetSuit(char _suit);
		
		char GetSuit() const;
		
		bool SetVal(char _val);
		
		char GetVal() const;
		
		bool operator> (const Card& _card) const; /* compare suit enum */
		
		bool operator< (const Card& _card) const; /* compare suit enum */
		
		bool operator>> (const Card& _card) const; /* compare val enum */
		
		bool operator<< (const Card& _card) const; /* compare val enum */
		
		bool operator== (const Card& _card) const; /* compare suit char */
		
		void PrintCard() const;
		
	private:
		Card(const Card& _card);
		
		char			m_suit;
		
		char 			m_val;
		
		CardSuit		m_suitEnum;
		
		CardVal 		m_valEnum;
};


/***************
inline functions
****************/
inline Card::Card(){}


inline Card::~Card(){}


inline Card& Card::operator= (const Card& _card)
{
	SetSuit(_card.m_suit);
	
	SetVal(_card.m_val);
	
	return *this;
}


inline char Card::GetSuit() const
{
	return m_suit;
}


inline char Card::GetVal() const
{
	return m_val;
}


inline bool Card::operator> (const Card& _card) const
{
	return m_suitEnum > _card.m_suitEnum ? true : false;
}


inline bool Card::operator< (const Card& _card) const
{
	return m_suitEnum < _card.m_suitEnum ? true : false;
}


inline bool Card::operator>> (const Card& _card) const
{
	return m_valEnum > _card.m_valEnum ? true : false;
}


inline bool Card::operator<< (const Card& _card) const
{
	return m_valEnum < _card.m_valEnum ? true : false;
}


inline bool Card::operator== (const Card& _card) const
{	
	return m_suitEnum == _card.m_suitEnum ? true : false;
}


inline void Card::PrintCard() const
{
	std::cout << m_suit << m_val;
	
	return;
}


#endif /*#ifndef __CARD_H__*/


