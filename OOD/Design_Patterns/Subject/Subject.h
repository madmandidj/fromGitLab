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
		
	protected:
		virtual void Notify(const string& _accountType);
		
	private:
		multimap<string, Observer*> m_observers;
};










#endif /* #ifndef __SUBJECT_H__ */


