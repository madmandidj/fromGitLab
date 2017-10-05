#ifndef __PLAYERS_H__
#define __PLAYERS_H__

#include "../Player/Player.h"
#include <stddef.h>
#include <vector>

class Players
{
	public:
		Players(Cards* _deck, Cards* _board);
		
		~Players();
		
		Player* operator[] (size_t _index) const;
		
		Player* GetPlayer(size_t _index) const;
		
		void ShowPlayersCards() const;
		
		static size_t GetNumOfPlayers();
		
		static void SetNumOfPlayers(size_t _numOfPlayers);
		
		Cards* m_deck;
		
		Cards* m_board;
		
	private:
		Players(Players& _players);
		
		Players& operator= (Players& _players);
		
		std::vector<Player*> m_players;
		
		static size_t m_numOfPlayers;
};









































#endif /*#ifndef __PLAYERS_H__*/
