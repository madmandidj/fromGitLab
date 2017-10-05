#include "Player.h"
#include <iostream>
#include <stdlib.h>



unsigned int Player::m_ID = 0;


unsigned int Player::GetID()
{
	return m_ID++;
}

unsigned int Player::GetMyID() const
{
	return m_myID;
}


Player::Player(Cards* _deck, Cards* _board)
{
	m_myID = Player::GetID();	
	
	if (!_deck || !_board)
	{
		exit(EXIT_FAILURE);
	}
	
	m_deck = _deck;
	
	m_board = _board;
}
		
		
Player::~Player(){}


void Player::Attack()
{
	Card* card;
	
	size_t index = rand() % m_cards.GetNumOfCards();
	
	card = m_cards.GetCard(index);
	
	m_cards.RemoveCard(index);
	
	m_board->PushBackCard(card);
	
	return ;
}


bool Player::Defend()
{
	Card* attackCard;
	Card* defendCard;
	bool isDefended = false;
	size_t defendIndex = 0;
	size_t numOfCards = m_cards.GetNumOfCards();
	
	attackCard = m_board->GetCard(0);

	m_board->RemoveCard(0);
	
	while (defendIndex < numOfCards)
	{
		defendCard = m_cards.GetCard(defendIndex);
	
		if ((*defendCard == *attackCard) && (*defendCard >> *attackCard))
		{
			/* defend success */
			m_deck->PushBackCard(attackCard);
			
			m_deck->PushBackCard(defendCard);
			
			m_cards.RemoveCard(defendIndex);
			
			Attack();
			
			return true;
		}
	
		++defendIndex;
	}
	
	return false;
}


bool Player::IsWinner() const
{
	return 0 == m_cards.GetNumOfCards() ? true : false;
}


void Player::ShowCards() const
{
	std::cout << "Player #" << (GetMyID() + 1) << ": " << std::endl;
	
	std::cout << "***********" << std::endl;
	
	m_cards.PrintCards();
	
	std::cout << std::endl;
	
	return; 
}


void Player::TakeCard(Cards* _cards)
{
	m_cards.PushBackCard(_cards->GetCard(0));
	
	_cards->RemoveCard(0);
	
	return;
}


void Player::SortCards()
{
	m_cards.Sort();
}










