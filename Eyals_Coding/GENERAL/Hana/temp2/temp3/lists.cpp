#include <list>
#include <set>

#include "lists.h"



using namespace std;


void RemoveDuplicates(list<int>& _list)
{
	set<int> uniqueElements;
	list<int>::iterator iter = _list.begin();
	list<int>::iterator next;
	pair<set<int>::iterator, bool> res;
	
	while (iter != _list.end())
	{
		res = uniqueElements.insert(*iter);
		if (!res.second)
		{
			next = iter++;
			_list.erase(iter);
			iter = next;
			continue;
		}
		iter++;
	}
}








