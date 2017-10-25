#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include<map>

using namespace std;

public Subject
{
	public:
		Subject();
		virtual ~Subject();
		virtual void Attach(Observer* _observer);
		virtual void Detach(Observer* _observer);
		
	protected:
		virtual void Notify(string& _accountType);
		
	private:
		multimap<string, Observer*> m_observers;
};










#endif /* #ifndef __SUBJECT_H__ */


