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
	
//	Player player;//currentAttacker;
	
//	player = (m_players->at(currentAttacker));//currentAttacker;
	
//	Player* player = m_players->GetPlayer(0);

	attackPlayer->Attack();
	
	isAttackerWinner = (attackPlayer->IsWinner());
	
	numOfWinners = (true == isAttackerWinner) ? ++numOfWinners : numOfWinners;
	
	if (true == (defendPlayer->Defend()))
	{
		isDefenderWinner = defendPlayer->IsWinner();
		
		numOfWinners = (true == isDefenderWinner) ? ++numOfWinners : numOfWinners;
	}
	else
	{
		++_curRound;
	}
	
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
	size_t numOfRounds = 40;
	size_t currentAttacker = 0;
	size_t currentDefender = 1;
	bool isWinner = 0;
	size_t numOfPlayers = GetNumOfPlayers();
	
	while (currentRound < numOfRounds)
	{
		
		isWinner = PlayRound(numOfPlayers, currentRound);
		
		if (isWinner)
		{
//			PrintFinalScore();
			Stop();
			return;
		}
		
		if(true == m_printMode)
		{
			std::cout << "Round " << currentRound << std::endl;
			Pause();
		} 
		
		++currentRound;
	}
	
//	SetWinners();
	
//	PrintFinalScore();
	
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
	m_players->ShowPlayersCards();
	
	int resume;
	
	std::cin >> resume;
}



void BareketCards::Stop()
{
	m_players->ShowPlayersCards();
}


void BareketCards::Quit()
{

}





//void BareketCards::PrintScore()
//{

//}


//void BareketCards::PrintFinalScore()
//{

//}


//bool BareketCards::GetPrintMode()
//{
//	return true;
//}


//void BareketCards::SetPrintMode()
//{

//}





size_t BareketCards::GetNumOfPlayers() const
{
	return Players::GetNumOfPlayers();
}


void BareketCards::SetNumOfPlayers(size_t _numOfPlayers)
{
	Players::SetNumOfPlayers(_numOfPlayers);
	
	return;
}







