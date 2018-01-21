#include "Player.h"
#include <iostream>
#include <stdlib.h>

/**********************
Public member functions
**********************/
Player::Player(unsigned int _playerID, Cards* const _deck, Cards* const _board)
{
	SetMyID(_playerID);
	
	if (0 == _deck || 0 == _board)
	{
		/*TODO: handle null pointers*/
	}
	
	m_deck = _deck;
	
	m_board = _board;
	
	m_cards = new Cards;
	
	if (0 == m_cards)
	{
		/*TODO: handle new exception*/
	}
}


void Player::TakeCard(Cards* _cards)
{
	m_cards->PushBackCard(_cards->GetCard(0));
	
	_cards->RemoveCard(0);
	
	return;
}


void Player::Attack()
{
	Card* card;
	
	size_t index = rand() % m_cards->GetNumOfCards();
	
	card = m_cards->GetCard(index);
	
	m_cards->RemoveCard(index);
	
	m_board->PushBackCard(card);
	
	std::cout << "Player #" << GetMyID() << " attacking with: ";
	
	card->PrintCard();
	
	std::cout << std::endl;
	
	return ;
}


bool Player::Defend()
{
	Card* attackCard;
	Card* defendCard;
	size_t defendIndex = 0;
	size_t numOfCards = m_cards->GetNumOfCards();
	
	attackCard = m_board->GetCard(0);

	m_board->RemoveCard(0);
	
	while (defendIndex < numOfCards)
	{
		defendCard = m_cards->GetCard(defendIndex);
	
		/* if defend successful */
		if ((*defendCard == *attackCard) && (*defendCard >> *attackCard))
		{
			m_deck->PushBackCard(attackCard);
			
			m_deck->PushBackCard(defendCard);
			
			m_cards->RemoveCard(defendIndex);

			std::cout << "Player #" << GetMyID() << " defended with: ";
	
			defendCard->PrintCard();
	
			std::cout << std::endl;
			
			return true;
		}
	
		++defendIndex;
	}
	
	m_cards->PushBackCard(attackCard);

	std::cout << "Player #" << GetMyID() << " failed to defend! Took: ";

	attackCard->PrintCard();

	std::cout << std::endl;
	
	SortCards();
	
	return false;
}


bool Player::IsWinner() const
{
	return 0 == m_cards->GetNumOfCards() ? true : false;
}


void Player::ReturnCardsToDeck()
{
	size_t numOfCards = m_cards->GetNumOfCards();
	
	Card* card;
	
	for (size_t index = 0; index < numOfCards; ++index)
	{
		card = m_cards->GetCard(0);
		
		m_deck->PushBackCard(card);
		
		m_cards->RemoveCard(0);
	}
}


void Player::ShowCards() const
{
	std::cout << "Player #" << (GetMyID()) << ": " << std::endl;
	
	std::cout << "***********" << std::endl;
	
	m_cards->PrintCards();
	
	std::cout << std::endl;
	
	return; 
}









