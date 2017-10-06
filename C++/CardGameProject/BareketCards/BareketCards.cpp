#include "BareketCards.h"
#include "../Players/Players.h"
#include "../Player/Player.h"
#include "../Cards/Cards.h"
#include "../Card/Card.h"
//#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>


/********
Private member functions
*********/
void BareketCards::CreateDeck()
{
//	Cards hand1;
//	Cards hand2;
//	Cards deck;
//	Cards board;
	
	
	
	size_t suitIndex;
	size_t valIndex;
	size_t deckIndex = 0;
	CardSuit cardSuit;
	const char SuitCharArr[] = {'C', 'D', 'H', 'S'};
	const char ValCharArr[] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
	Card* getCard;
	
	Card* getCard2;
	
//	Card cards[52];
	
	srand(time(0));
	
	for(suitIndex = 0; suitIndex < numOfSuits; ++suitIndex)
	{
		for (valIndex = 0; valIndex < numOfVals; ++valIndex)
		{	
			Card* card = new Card;
			
			/*TODO: handle new exception */
			
			card->SetSuit(SuitCharArr[suitIndex]);
			
			card->SetVal(ValCharArr[valIndex]);
			
//			_deck->PushBackCard(card);

			m_deck->PushBackCard(card);
			
			++deckIndex; 
			
			
//			cards[deckIndex].SetSuit(SuitCharArr[suitIndex]);
//		
//			cards[deckIndex].SetVal(ValCharArr[valIndex]);
//			
//			deck.PushBackCard(cards + deckIndex);
//			
//			++deckIndex; 

			

//			_deck->GetCard(deckIndex).SetSuit(SuitCharArr[suitIndex]);
//		
//			cards[deckIndex].SetVal(ValCharArr[valIndex]);
//			
//			deck.PushBackCard(cards + deckIndex);
//			
//			++deckIndex; 
			
		}
	}
	
	
	return;
}



/********
Public member functions
*********/
BareketCards::BareketCards()
{
//	size_t numOfPlayers = GetNumOfPlayers();
	
	m_deck = new Cards;
	if (0 == m_deck)
	{
		// TODO: Handle new exception
	}
	
	CreateDeck();
	
	m_board = new Cards;
	if (0 == m_board)
	{
		// TODO: Handle new exception
	}
	
//	InitBoard();
	
	m_players = new Players(m_deck, m_board);
	if (0 == m_players)
	{
		// TODO: Handle new exception
	}
	
	m_printMode = true;
	
	m_quit = false;
}


BareketCards::~BareketCards()
{	
	delete m_deck;
	
	delete m_board;
	
	delete m_players;
}


bool BareketCards::PlayRound(size_t _numOfPlayers, size_t& _curRound)
{	
	int numOfWinners = 0;	
	
	size_t currentAttacker = _curRound % _numOfPlayers;
	
	size_t currentDefender = (_curRound + 1) % _numOfPlayers;
	
	Player* attackPlayer = m_players->GetPlayer(currentAttacker);
	
	Player* defendPlayer = m_players->GetPlayer(currentDefender);
	
	
	bool isAttackerWinner = false;
	
	bool isDefenderWinner = false;
	
	std::cout << "Round #" << _curRound << std::endl << std::endl;
	
//	m_players->ShowPlayersCards();
	
//	std::cout << "Attacker = Player #" << currentAttacker + 1 << std::endl;
	
	attackPlayer->Attack();
	
//	m_players->ShowPlayersCards();
	
	isAttackerWinner = (attackPlayer->IsWinner());
	
	numOfWinners = (true == isAttackerWinner) ? ++numOfWinners : numOfWinners;
	
//	std::cout << "Defender = Player #" << currentDefender + 1 << std::endl;
	
	if (true == (defendPlayer->Defend()))
	{
//		m_players->ShowPlayersCards();
		
		isDefenderWinner = defendPlayer->IsWinner();
		
		numOfWinners = (true == isDefenderWinner) ? ++numOfWinners : numOfWinners;
	}
	else
	{
		++_curRound;
	}
	
//	m_players->ShowPlayersCards();
	
	if(numOfWinners > 0)
	{
		/*TODO:
		Check if overtime needed and do it
		*/
		
		return true;
	}
	
	return false;
}


void BareketCards::Start()
{
	size_t currentRound = 0;
	size_t numOfRounds = 60;
	size_t currentAttacker = 0;
	size_t currentDefender = 1;
	bool isWinner = 0;
	size_t numOfPlayers = GetNumOfPlayers();
	
	while (currentRound < numOfRounds && m_quit == false)
	{
		
		isWinner = PlayRound(numOfPlayers, currentRound);
		
		if (isWinner)
		{
			Stop();
			continue;
//			return;
		}
		
		if(true == m_printMode)
		{
			std::cout << "Pause end of round: " << currentRound + 1 << std::endl << std::endl;
			m_players->ShowPlayersCards();
			Pause();
		} 
		
		++currentRound;
	}
	
	return;
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
	size_t numOfPlayers = GetNumOfPlayers();
	
	for (cardNum = 0; cardNum < numOfVals; ++cardNum)
	{
		for (playerNum = 0; playerNum < numOfPlayers; ++playerNum)
		{
			Player* player = m_players->GetPlayer(playerNum);
			
			player->TakeCard(m_deck);
		}
	}
	
	for (playerNum = 0; playerNum < numOfPlayers; ++playerNum)
	{
		Player* player = m_players->GetPlayer(playerNum);
		
		player->SortCards();
	}
	
	
	
	return;
}


void BareketCards::Restart()
{

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
			m_quit = true;
			
		default:
			break;
	}
}



void BareketCards::Stop()
{
	std::cout << std::endl << std::endl << "Final Score is:" << std::endl;
	m_players->ShowPlayersCards();
	Quit();
}


void BareketCards::Quit()
{
	m_quit = true;
}





void BareketCards::PrintScore(size_t _playerNum) const
{
	Player* player = m_players->GetPlayer(_playerNum);
	
	player->ShowCards();
}


//void BareketCards::PrintFinalScore()
//{

//}


bool BareketCards::GetPrintMode() const
{
	return m_printMode;
}


void BareketCards::SetPrintMode(bool _printMode)
{
	m_printMode = _printMode;
}





size_t BareketCards::GetNumOfPlayers() const
{
	return Players::GetNumOfPlayers();
}


void BareketCards::SetNumOfPlayers(size_t _numOfPlayers)
{
	Players::SetNumOfPlayers(_numOfPlayers);
	
	return;
}







