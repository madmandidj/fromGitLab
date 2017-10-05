#include "Card.h"
#include <stdlib.h>

void Card::SetSuit(char _suit)
{
	m_suit = _suit;	
	
	switch(m_suit)
	{
		case 'C':
			m_suitEnum = Clubs;
			break;
		
		case 'D':
			m_suitEnum = Diamonds;
			break;
		
		case 'H':
			m_suitEnum = Hearts;
			break;
		
		case 'S':
			m_suitEnum = Spades;
			break;
		
		default:
			exit(EXIT_FAILURE);
			break;
	}
	
	return;
}


bool Card::SetVal(char _val)
{
	m_val = _val;	
	
	switch(m_val)
	{
		case '2':
			m_valEnum = Two;
			return true;
		
		case '3':
			m_valEnum = Three;
			return true;
		
		case '4':
			m_valEnum = Four;
			return true;
			
		case '5':
			m_valEnum = Five;
			return true;
		
		case '6':
			m_valEnum = Six;
			return true;
		
		case '7':
			m_valEnum = Seven;
			return true;
		
		case '8':
			m_valEnum = Eight;
			return true;
		
		case '9':
			m_valEnum = Nine;
			return true;
		
		case 'T':
			m_valEnum = Ten;
			return true;
		
		case 'J':
			m_valEnum = Jack;
			return true;
		
		case 'Q':
			m_valEnum = Queen;
			return true;
		
		case 'K':
			m_valEnum = King;
			return true;
			
		case 'A':
			m_valEnum = Ace;
			return true;
			
		default:
			break;
	}
	
	return false;
}


bool Card::operator> (const Card& _card) const
{
	return m_suitEnum > _card.m_suitEnum ? true : false;
}


bool Card::operator< (const Card& _card) const
{
	return m_suitEnum < _card.m_suitEnum ? true : false;
}


bool Card::operator>> (const Card& _card) const
{
	return m_valEnum > _card.m_valEnum ? true : false;
}


bool Card::operator<< (const Card& _card) const
{
	return m_valEnum < _card.m_valEnum ? true : false;
}


bool Card::operator== (const Card& _card) const
{	
	return m_suitEnum == _card.m_suitEnum ? true : false;
}



