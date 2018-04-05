#include <list>
#include <stdio.h>
#include <iostream>

#include "../../macro_test.h"
#include "lists.h"


using namespace std;

int main()
{
	list<int> list;
	list.push_front(12);
	list.push_front(7);
	list.push_front(2);
	list.push_front(9);
	list.push_front(12);
	list.push_front(12);
	list.push_front(19);

	RemoveDuplicates(list);
	cout << list.size() << endl;
	
	return 0;
}


//UNIT(remove_duplicates)
//	list<int> list;
//	list.push_front(12);
//	list.push_front(7);
//	list.push_front(2);
//	list.push_front(9);
//	list.push_front(12);
//	list.push_front(12);
//	list.push_front(19);

//	RemoveDuplicates(list);
//	
//	cout << list.size() << endl;
//	ASSERT_THAT(list.size() == 	5);
//END_UNIT



//TEST_SUITE(creacking lists)
//	TEST(remove_duplicates)
//END_SUITE



