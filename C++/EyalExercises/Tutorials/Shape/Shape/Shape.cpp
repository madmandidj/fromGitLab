#include <iostream>
#include "Shape.h"

using namespace std;


Shape::Shape(int a, int b)
{
	width = a;
	height = b;
}


int Shape::Area()
{
	cout<< "Parent class area: " << width * height << endl;
	
	return 0;
}

int Triangle::Area()
{
	cout<< "Triangle class area: " << width * height << endl;
	
	return 1;
}













