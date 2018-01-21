#include "Buffer.h"
#include<iostream>

//using namespace advcpp;

using namespace std;

int main()
{
	const char* temp;
	advcpp::Buffer<char> buf;
	
	buf.SetBuffer("Yooo", 5);
	temp = buf.GetBuffer();
	cout << temp << endl;
	
	buf.SetElement('c', 4);
	temp = buf.GetBuffer();
	cout << temp << endl;
	
	char c = buf.GetElement(0);
	cout << c << endl;
	
	cout << buf.GetCapacity() << endl;
	
	cout << buf.GetSize() << endl;
	
	return 0;
}


