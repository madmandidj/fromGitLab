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
//		std::cout << "Football starting to push to queue" << std::endl;
//		std::cout << "priority = " << m_priority << std::endl;
		m_tspq->Push(*this);
//		std::cout << "Football finished to push to queue" << std::endl;
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
	const size_t numOfThreads = 100;
	std::vector< advcpp::Thread<FootballTeam, &FootballTeam::DoSumfink>* > threadsVec;
	std::vector<FootballTeam*> teamsVec;
	
	for (size_t index = 0; index < numOfThreads; ++index)
	{	
		FootballTeam* team = new FootballTeam(index, &myTSPQ);
		advcpp::Thread<FootballTeam, &FootballTeam::DoSumfink>* thread = new advcpp::Thread<FootballTeam, &FootballTeam::DoSumfink>(team);
		threadsVec.push_back(thread);
		teamsVec.push_back(team);
		//team and thread should be stored as pairs so both can be deleted properly, otherwise might delete mismatching thread/team
	}
	
	
	for (size_t index = 0; index < numOfThreads; ++index)
	{	
		
		advcpp::Thread<FootballTeam, &FootballTeam::DoSumfink>* thread = threadsVec[index];
		thread->Join();
		FootballTeam teamPQ = myTSPQ.Top();
		std::cout << teamPQ.GetPriority() <<std::endl;
		myTSPQ.Pop();
		delete thread;
		FootballTeam* team = teamsVec.back();
		delete team;
		threadsVec.pop_back();
		teamsVec.pop_back();
	}
	
	// while(!myTSPQ.IsEmpty())
	// {
	// 	FootballTeam teamPQ = myTSPQ.Top();
	// 	std::cout << teamPQ.GetPriority() <<std::endl;
	// 	advcpp::Thread<FootballTeam, &FootballTeam::DoSumfink>* thread = threadsVec.back();
	// 	delete thread;
	// 	FootballTeam* team = teamsVec.back();
	// 	delete team;
	// 	threadsVec.pop_back();
	// 	teamsVec.pop_back();
		
	// }

	return 0;
}
