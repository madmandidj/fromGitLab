#include "TSPQ.h"
#include "../Thread/Thread.h"
#include<iostream>

class FootballTeam
{
public:
	FootballTeam(int _priority, advcpp::TSPQ<FootballTeam>* _tspq):m_tspq(_tspq), m_priority(_priority){}
	int GetPriority() const {return m_priority;}
	void* DoSumfink()
	{
		m_tspq->Push(*this);
		return 0;
	}
	bool operator<(const FootballTeam& _rhs) const
	{
		return (GetPriority() < _rhs.GetPriority());
	}
private:
	advcpp::TSPQ<FootballTeam>* m_tspq;
	int m_priority;
};


int main()
{
	advcpp::TSPQ<FootballTeam> myTSPQ;
	FootballTeam mhaifa(25, &myTSPQ);
	FootballTeam hhaifa(1, &myTSPQ);
	FootballTeam mtelaviv(3, &myTSPQ);
	FootballTeam htelaviv(6, &myTSPQ);
	const size_t numOfThreads = 5;
	std::vector< advcpp::Thread<FootballTeam, &FootballTeam::DoSumfink>* > threadsVec;
	std::vector<FootballTeam*> teamsVec;
	
	for (size_t index = 0; index < numOfThreads; ++index)
	{	
		FootballTeam* team = new FootballTeam(index, &myTSPQ);
		advcpp::Thread<FootballTeam, &FootballTeam::DoSumfink>* thread = new advcpp::Thread<FootballTeam, &FootballTeam::DoSumfink>(team);
		threadsVec.push_back(thread);
		teamsVec.push_back(team);
	}
	for (size_t index = 0; index < numOfThreads; ++index)
	{	
		
		advcpp::Thread<FootballTeam, &FootballTeam::DoSumfink>* thread = threadsVec.back();
		thread->Join();
		delete thread;
		threadsVec.pop_back();
	}
	for (size_t index = 0; index < numOfThreads; ++index)
	{	
		FootballTeam test(25, &myTSPQ);
		myTSPQ.Pop(&test);
		std::cout << test.GetPriority() <<std::endl;
		FootballTeam* team = teamsVec.back();
		delete team;
		teamsVec.pop_back();
	}

	return 0;
}
