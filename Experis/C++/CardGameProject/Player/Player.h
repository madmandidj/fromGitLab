#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../Cards/Cards.h"
#include <iostream>

class Player
{
	public:
		Player(unsigned int _playerID, Cards* const _deck, Cards* const _board);
		
		~Player();
		
		void SetMyID(unsigned int _playerID);
		
		unsigned int GetMyID() const;
		
		void TakeCard(Cards* _cards);
		
		void SortCards(); /*TODO: should not be public */
	
		void Attack(); /*TODO: should return Card**/
		
		bool Defend(); /*TODO: should return Card**/
		
		bool IsWinner() const;
		
		void ReturnCardsToDeck();
		
		void ShowCards() const;
		
	private:
		Player(Player& _player);
		
		Player& operator= (Player& _player);
	
	private:
		Cards* m_cards;
		
		Cards* m_deck;
		
		Cards* m_board;
		
		unsigned int m_myID;
};


/***************
inline functions
****************/
inline Player::~Player()
{
	delete m_cards;
}


inline void Player::SetMyID(unsigned int _myID)
{
	m_myID = _myID;
}

inline unsigned int Player::GetMyID() const
{
	return m_myID;
}


inline void Player::SortCards()
{
	m_cards->Sort();
}















#endif /*#ifndef __PLAYER_H__*/


