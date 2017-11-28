#include<iostream>
#include<queue>

class FootBallTeam
{
public:
	virtual ~FootBallTeam(){}
	virtual int GetPriority() const =0;
};

class MHaifa : public FootBallTeam
{
public:
	MHaifa(int _priority):m_priority(_priority){}
	virtual int GetPriority() const {return m_priority;}
	bool operator<(const MHaifa& _rhs) const
	{
		return m_priority < _rhs.GetPriority();
	}
private:
	int m_priority;
};

class MTelAviv : public FootBallTeam
{	
public:
	MTelAviv(int _priority):m_priority(_priority){}
	virtual int GetPriority() const {return m_priority;}
private:
	int m_priority;
};


class ComparePriority
{
public:
  bool operator() (const FootBallTeam* _lhs, const FootBallTeam* _rhs) const
  {
    return (_lhs->GetPriority() < _rhs->GetPriority());
  }
//  bool operator==
};

int main()
{
//	MTelAviv mtlv(2);
//	MHaifa mhfa(8);
//	MHaifa mhfa84(25);
//	MHaifa mhfa00(0);
//	std::priority_queue<FootBallTeam*, std::vector<FootBallTeam*>, ComparePriority> myPQ;
//	myPQ.push(&mtlv);
//	myPQ.push(&mhfa00);
//	myPQ.push(&mhfa84);
//	myPQ.push(&mhfa);
//	FootBallTeam* ftbPtr = myPQ.top();
//	std::cout << ftbPtr->GetPriority() << std::endl;
//	myPQ.pop();
//	ftbPtr = myPQ.top();
//	std::cout << ftbPtr->GetPriority() << std::endl;
//		myPQ.pop();
//	ftbPtr = myPQ.top();
//	std::cout << ftbPtr->GetPriority() << std::endl;
//		myPQ.pop();
//	ftbPtr = myPQ.top();
//	std::cout << ftbPtr->GetPriority() << std::endl;
//	return 0;

	MHaifa mtlv(2);
	MHaifa mhfa(8);
	MHaifa mhfa84(25);
	MHaifa mhfa00(0);
	std::priority_queue<MHaifa, std::vector<MHaifa> > myPQ;
	// myPQ.push(mtlv);
	// myPQ.push(mhfa00);
	// myPQ.push(mhfa84);
	// myPQ.push(mhfa);
	const MHaifa& ftbPtr = myPQ.top();
	// std::cout << ftbPtr.GetPriority() << std::endl;
	// myPQ.pop();
	// myPQ.top();
//	ftbPtr = myPQ.top();
//	std::cout << ftbPtr->GetPriority() << std::endl;
//	myPQ.pop();
//	ftbPtr = myPQ.top();
//	std::cout << ftbPtr->GetPriority() << std::endl;
//	myPQ.pop();
//	ftbPtr = myPQ.top();
//	std::cout << ftbPtr->GetPriority() << std::endl;
	return 0;

}



