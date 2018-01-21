#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

ostream& PrintDividerLine(ostream& _os)
{
	return _os << endl << "|---------------|" << endl;
}


void 


int main()
{
	string name1;
	string name2;
	size_t ID1;
	size_t ID2;
	
	ofstream outFile("TestFile.txt", ios::out);
	
	cout << "Enter Name 1" << endl;
	
	cin >> name1;
	
	cout << "Enter ID 1" << endl;
	
	cin >> ID1;
	
	while (!cin.good())
	{
		cout << "invalid ID, enter again" << endl;

		cin.clear();
		
		cin.ignore(1, ' ');
		
		cin >> ID1;
	}
	
	cout << "Enter Name 2" << endl;
	
	cin >> name2;
	
	cout << "Enter ID 2" << endl;
	
	cin >> ID2;
	
	outFile << setw(32)	<< setfill('.') << left << ID1 << setw(32) << name1 << PrintDividerLine;
}
























