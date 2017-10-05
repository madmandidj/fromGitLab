#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../Card/Card.h"
#include "../Cards/Cards.h"

#include <iostream>

class Player
{
	public:
		Player(Cards* _deck, Cards* _board);
		
		~Player();
	
		void Attack();
		
		bool Defend();
		
		bool IsWinner() const;
		
		void SortCards();
		
		void ShowCards() const;
		
		void TakeCard(Cards* _cards);
		
		unsigned int GetMyID() const;
		
		static unsigned int GetID();
		
	private:
		Player(Player& _player);
		
		Player& operator= (Player& _player);
		
		Cards m_cards; /*TODO: change this to Cards* */
		
		Cards* m_deck;
		
		Cards* m_board;
		
		unsigned int m_myID;
		
		static unsigned int m_ID;
};




















#endif /*#ifndef __PLAYER_H__*/


