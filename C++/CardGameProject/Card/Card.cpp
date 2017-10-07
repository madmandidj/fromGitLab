#include "Card.h"


/**********************
Public member functions
**********************/
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
			/*TODO: Handle error char */
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
			/*TODO: Handle error char */
			break;
	}
	
	return false;
}


