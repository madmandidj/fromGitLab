#include "Players.h"


/**********************
Public member functions
**********************/
Players::Players(size_t _numOfPlayers, Cards* const _deck, Cards* const _board)
{
	size_t index;
	
	SetNumOfPlayers(_numOfPlayers);
	
	for (index = 0; index < m_numOfPlayers; ++index)
	{
		Player* player = new Player(index + 1, _deck, _board);
		
		if (0 == player)
		{
			/*TODO Handle new exception*/
		}
		
		m_playersVec.push_back(player);
	}
}
		
		
Players::~Players()
{
	size_t index;
	
	for (index = 0; index < m_numOfPlayers; ++index)
	{
		delete m_playersVec[0];
		
		m_playersVec.erase(m_playersVec.begin());
	}
}


void Players::ShowPlayersCards() const
{
	size_t index;
	
	for (index = 0; index < m_numOfPlayers; ++index)
	{
		m_playersVec[index]->ShowCards();
	}
	
	return;
}


