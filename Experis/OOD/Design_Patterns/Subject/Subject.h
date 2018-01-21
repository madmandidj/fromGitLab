#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <map>
#include <string>
class Observer;

using namespace std;

class Subject
{
	public:
		Subject();
		virtual ~Subject();
		virtual void Attach(const string& _accountType, Observer* _observer);
		virtual void Detach(const string& _accountType, Observer* _observer);
		virtual void Notify(const string& _accountType);
		
	protected:
		
		
	private:
		multimap<string, Observer*> m_observers;
};










#endif /* #ifndef __SUBJECT_H__ */


