#ifndef __BAREKET_CARDS_H__
#define __BAREKET_CARDS_H__

#include "../CardGame/CardGame.h"

class BareketCards:public CardGame
{
	public:
		BareketCards();
		
		virtual ~BareketCards();
		
		virtual void Shuffle();
		
		virtual void Deal();
		
		virtual void Start();
		
		virtual void Pause();
		
		virtual void Stop();
		
		virtual void Quit();
		
		void PrintScore(size_t _playerNum) const;
		
		void PrintWinners() const;
		
		void ShowDeck() const;
		
		bool GetPrintMode() const;
		
		void SetPrintMode(bool _printMode);
		
		size_t GetNumOfPlayers() const;
		
	public:
		static void SetDefaultNumOfPlayers(size_t _numOfPlayers);
		
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
		
		void CreateDeck();
		
		bool PlayRound(size_t& _curRound);
		
		void ReturnCardsToDeck();
		
		void DestroyDeck();
		
	private:	
		size_t 			m_numOfPlayers;
		
		bool 			m_quitFlag;
		
		bool 			m_printMode;	
		
	private:
		static size_t 	m_defaultNumOfPlayers;
};




/***************
inline functions
****************/
inline void BareketCards::Quit()
{
	ReturnCardsToDeck();
}


inline void BareketCards::ShowDeck() const
{
	m_deck->PrintCards();
}


inline bool BareketCards::GetPrintMode() const
{
	return m_printMode;
}


inline void BareketCards::SetPrintMode(bool _printMode)
{
	m_printMode = _printMode;
}


inline size_t BareketCards::GetNumOfPlayers() const
{
	return m_numOfPlayers;
}






















#endif /* #ifndef __BAREKET_CARDS_H__ */


