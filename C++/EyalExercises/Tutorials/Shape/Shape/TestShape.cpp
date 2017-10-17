#include <iostream>
#include "Shape.h"

using namespace std;


int main()
{
//	Shape s1(5,5);
	Triangle t1(6,6);
	
//	s1.Area();
	t1.Area();
	
	Shape* sp;
	
//	sp = &s1;
//	sp->Area();
	
	sp = &t1;
	sp->Area();
	
	return 0;
}






















