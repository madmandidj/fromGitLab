#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class Subject;
using namespace std;

class Observer
{
	public:	
		virtual ~Observer();
		virtual void Update(Subject* _subject) = 0;

	protected:
		Observer();
		Subject* m_subject;
};





#endif /* #ifndef __OBSERVER_H__ */





