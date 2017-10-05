#ifndef __CARD_GAME_H__
#define __CARD_GAME_H__

#include "../Cards/Cards.h"
#include "../Players/Players.h"

class CardGame
{
	public:
		CardGame();
		
		virtual ~CardGame();
				
		virtual void Shuffle() = 0;
		
		virtual void Deal() = 0;
		
		virtual void Start() = 0;
		
		virtual void Restart() = 0;
		
		virtual void Pause() = 0;
			
		virtual void Stop() = 0;
		
		virtual void Quit() = 0;

	protected:	
		Players* 		m_players;
		
		Cards*  		m_deck;
		
		Cards*			m_board;
	
	private:
		CardGame(CardGame& _cardGame);
		
		CardGame& operator= (CardGame& _cardGame);
};


inline CardGame::CardGame(){}

inline CardGame::~CardGame(){}


#endif /*#ifndef __CARD_GAME_H__*/
