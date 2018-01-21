#ifndef __PLAYERS_H__
#define __PLAYERS_H__

#include "../Player/Player.h"
#include <stddef.h>
#include <vector>

class Players
{
	public:
		Players(size_t _numOfPlayers, Cards* const _deck, Cards* const _board);
		
		~Players();
		
		size_t GetNumOfPlayers();
		
		void SetNumOfPlayers(size_t _numOfPlayers);
		
		Player* operator[] (size_t _index) const; /*TODO: Debug! Use GetPlayer() for now */
		
		Player* GetPlayer(size_t _index) const;
		
		void ShowPlayersCards() const;
		
	private:
		Players(Players& _players);
		
		Players& operator= (Players& _players);
	
	private:
		std::vector<Player*> m_playersVec;
		
		size_t m_numOfPlayers;
};



/***************
inline functions
****************/
inline Player* Players::operator[] (size_t _index) const
{
	return m_playersVec[_index];
}

inline Player* Players::GetPlayer(size_t _index) const
{
	return m_playersVec[_index];
}
		
		
inline size_t Players::GetNumOfPlayers()
{
	return m_numOfPlayers;
}
		
		
inline void Players::SetNumOfPlayers(size_t _numOfPlayers)
{
	m_numOfPlayers = _numOfPlayers;	
	
	return;
}
































#endif /*#ifndef __PLAYERS_H__*/
