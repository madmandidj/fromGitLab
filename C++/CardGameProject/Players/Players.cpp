#include "Players.h"
#include <stdlib.h>

size_t Players::m_numOfPlayers = 4;


Players::Players(Cards* _deck, Cards* _board)
{
	size_t index;
	
	for (index = 0; index < Players::m_numOfPlayers; ++index)
	{
		Player* player = new Player(_deck, _board);
		
		if (0 == player)
		{
			exit(EXIT_FAILURE);
		}
		
		m_players.push_back(player);
	}
	
	m_deck = _deck;
	
	m_board = _board;
}
		
		
Players::~Players()
{
	size_t index;
	
	for (index = 0; index < Players::m_numOfPlayers; ++index)
	{
		delete m_players[0];
		
		m_players.erase(m_players.begin());
	}
}


Player* Players::operator[] (size_t _index) const
{
	return m_players[_index];
}

Player* Players::GetPlayer(size_t _index) const
{
	return m_players[_index];
}
		
		
size_t Players::GetNumOfPlayers()
{
	return Players::m_numOfPlayers;
}
		
		
void Players::SetNumOfPlayers(size_t _numOfPlayers)
{
	Players::m_numOfPlayers == _numOfPlayers;	
	
	return;
}


void Players::ShowPlayersCards() const
{
	size_t index;
	
	for (index = 0; index < Players::m_numOfPlayers; ++index)
	{
		m_players[index]->ShowCards();
	}
	
	return;
}


