#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include<vector>

public Subject
{
	public:
		Subject();
		virtual ~Subject()
		void Attach(Observer*)
		void Detach(Observer*)
		
	protected:
		void virtual Notify();
		
	private:
		vector<Observer*>
};










#endif /* #ifndef __SUBJECT_H__ */


