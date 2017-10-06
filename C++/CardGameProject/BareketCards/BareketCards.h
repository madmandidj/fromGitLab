#ifndef __BAREKET_CARDS_H__
#define __BAREKET_CARDS_H__

#include "../CardGame/CardGame.h"
#include "../Players/Players.h"
//#include "../Player/Player.h"
#include "../Cards/Cards.h"
//#include "../Card/Card.h"


class BareketCards:public CardGame
{
	public:
		BareketCards();
		
		virtual ~BareketCards();
		
		virtual void Shuffle();
		
		virtual void Deal();
		
		virtual void Start();
		
		virtual void Restart();
		
		virtual void Pause();
		
		virtual void Stop();
		
		virtual void Quit();
		
		void PrintScore(size_t _playerNum) const;
		
		void PrintFinalScore() const;
		
		bool GetPrintMode() const;
		
		void SetPrintMode(bool _printMode);
		
		size_t GetNumOfPlayers() const;
		
		void SetNumOfPlayers(size_t _numOfPlayers);
		
	protected:	
	/***********************
		Inherited from CardGame:
		Players* 		m_players;
		Cards*  		m_deck;
		Cards*			m_board;
	***********************/
	
	private:
		BareketCards(BareketCards& _barCards);
		
		BareketCards& operator= (BareketCards& _barCards);
		
		bool m_quit;
		
		bool m_printMode;	
		
		void CreateDeck();
		
		bool PlayRound(size_t _numOfPlayers, size_t& _curRound);
};




























#endif /* #ifndef __BAREKET_CARDS_H__ */


