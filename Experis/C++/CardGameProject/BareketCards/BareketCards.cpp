#include "BareketCards.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

size_t BareketCards::m_defaultNumOfPlayers = 0;

const size_t NUM_OF_ROUNDS = 100;

/********
Public member functions
*********/
BareketCards::BareketCards()
{
	/****
	TODO: Handle all 'new' exceptions in constructor 
	*****/
	
	m_numOfPlayers = m_defaultNumOfPlayers;
	
	m_deck = new Cards;
	
	CreateDeck();
	
	m_board = new Cards;
	
	m_players = new Players(m_numOfPlayers, m_deck, m_board);
	
	m_printMode = false;
	
	m_quitFlag = false;
}


BareketCards::~BareketCards()
{	
	DestroyDeck();	
	
	delete m_deck;
	
	delete m_board;
	
	delete m_players;
}


void BareketCards::Shuffle()
{
	m_deck->Shuffle();
	
	return;
}


void BareketCards::Deal()
{
	size_t cardNum;
	size_t playerNum;
	
	for (cardNum = 0; cardNum < NUM_OF_VALS; ++cardNum)
	{
		for (playerNum = 0; playerNum < m_numOfPlayers; ++playerNum)
		{
			Player* player = m_players->GetPlayer(playerNum);
			
			player->TakeCard(m_deck);
		}
	}
	
	for (playerNum = 0; playerNum < m_numOfPlayers; ++playerNum)
	{
		Player* player = m_players->GetPlayer(playerNum);
		
		player->SortCards();
	}
	
	return;
}


void BareketCards::Start()
{
	size_t currentRound = 0;
	bool isWinner = false;
	
	while (currentRound < NUM_OF_ROUNDS && m_quitFlag == false)
	{
		
		isWinner = PlayRound(currentRound);
		
		if (isWinner)
		{
			Stop();
			continue;
		}
		
		if(true == m_printMode)
		{
			std::cout << "Pause end of round: " << currentRound + 1 << std::endl << std::endl;
			m_players->ShowPlayersCards();
			Pause();
		} 
		
		++currentRound;
	}
	
	ReturnCardsToDeck();

	m_quitFlag = false;
	
	return;
}


void BareketCards::Pause()
{
	char option;
	
	std::cout << "Enter: 'p' - play next round, 'm' - print mode off, 'q' - quit" << std::endl;
	
	std::cin >> option;
	
	switch (option)
	{
		case 'p':
			break;
			
		case 'm':
			SetPrintMode(false);
			break;
			
		case 'q':
			m_quitFlag = true;
			
		default:
			break;
	}
}


void BareketCards::Stop()
{
	std::cout << std::endl << std::endl << "The final score is:" << std::endl;
	
	m_players->ShowPlayersCards();
	
	PrintWinners();
	
	std::cout << "Thanks for playing Bareket Cards! :-)" << std::endl << std::endl;
	
	m_quitFlag = true;
}


void BareketCards::PrintScore(size_t _playerNum) const
{
	Player* player = m_players->GetPlayer(_playerNum);
	
	player->ShowCards();
}


void BareketCards::SetDefaultNumOfPlayers(size_t _numOfPlayers)
{
	m_defaultNumOfPlayers = _numOfPlayers;
	
	return;
}



/***********************
Private member functions
***********************/
void BareketCards::CreateDeck()
{
	size_t suitIndex;
	size_t valIndex;
	
	srand(time(0));
	
	for(suitIndex = 0; suitIndex < NUM_OF_SUITS; ++suitIndex)
	{
		for (valIndex = 0; valIndex < NUM_OF_VALS; ++valIndex)
		{	
			Card* card = new Card;
			
			if (0 == card)
			{
				/*TODO: handle new exception */
			}
			
			card->SetSuit(SUIT_CHAR_ARR[suitIndex]);
			
			card->SetVal(VAL_CHAR_ARR[valIndex]);

			m_deck->PushBackCard(card);		
		}
	}
	
	return;
}


bool BareketCards::PlayRound(size_t& _curRound)
{	
	int numOfWinners = 0;	
	size_t currentAttacker = _curRound % m_numOfPlayers;
	size_t currentDefender = (_curRound + 1) % m_numOfPlayers;
	Player* attackPlayer = m_players->GetPlayer(currentAttacker); /*TODO: use [] operator for player*/
	Player* defendPlayer = m_players->GetPlayer(currentDefender);
	bool isAttackerWinner = false;
	bool isDefenderWinner = false;
	
	std::cout << std::endl << std::endl << "Round #" << _curRound + 1 << std::endl;
	
	attackPlayer->Attack();
	
	isAttackerWinner = (attackPlayer->IsWinner());
	
	numOfWinners = (true == isAttackerWinner) ? numOfWinners + 1 : numOfWinners + 0;
	
	if (true == (defendPlayer->Defend()))
	{
		isDefenderWinner = defendPlayer->IsWinner();
		
		numOfWinners = (true == isDefenderWinner) ? numOfWinners + 1 : numOfWinners + 0;
	}
	else
	{
		++_curRound;
	}
	
	if(numOfWinners > 0)
	{
		/*TODO:
		Check if overtime!!
		*/
		
		return true;
	}
	
	return false;
}


void BareketCards::PrintWinners() const
{
	Player* player;
	
	std::cout << std::endl << "The winners are:";
	
	for (size_t index = 0; index < m_numOfPlayers; ++index)
	{
		player = m_players->GetPlayer(index); /*TODO: use [] operator for player*/
		
		if (true == player->IsWinner())
		{
			std::cout << " Player #" << (index + 1);
		}
	}
	
	std::cout << std::endl;
}


void BareketCards::ReturnCardsToDeck()
{
	Player* player;
	
	for (size_t index = 0; index < m_numOfPlayers; ++index)
	{
		player = m_players->GetPlayer(index); /*TODO: use [] operator for player*/
		
		player->ReturnCardsToDeck();
	}
}


void BareketCards::DestroyDeck()
{
	size_t numOfCards = m_deck->GetNumOfCards();
	
	Card* card;
	
	for (size_t index = 0; index < numOfCards; ++index)
	{
		card = m_deck->GetCard(0);
		
		m_deck->RemoveCard(0);
		
		delete card;
	}
}





