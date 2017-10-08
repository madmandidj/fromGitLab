#include "./memPool_t/memPool_t.h"
#include <iostream>

using namespace std;


typedef struct TwoBytes
{
	char byte1;
	char byte2;
	
}TwoBytes;

typedef struct ThreeBytes
{
	char byte1;
	char byte2;
	char byte3;
	
}ThreeBytes;


/*TODO: make test that use memMngr pointer to send Page or Pool to test()*/


int main()
{
	memPool_t* mPool;
	unsigned int option;
	unsigned int rwOption;
	size_t position;
	bool cont = true;
	bool memPoolExists = false;
	size_t readResult;
	size_t writeResult;

	char charVar = 127;
	TwoBytes twoBytes = {126,125};
	ThreeBytes threeBytes = {124, 123, 122};
	unsigned int intVar = 1234567890;
	double dblVar = 98765.01234;
	
	char readChar = 0;
	TwoBytes readTwoBytes = {0};
	ThreeBytes readThreeBytes = {0};
	int readInt = 0;
	double readDbl = 0.0;
	

	cout << endl << "Good morning, Yossi :-) Please select an option:" << endl << "************************************************" << endl;
		
	while (true == cont)
	{
		
		cout << endl << "1 - Create memory pool" << endl;
		cout << "2 - Get pool size" << endl;
		cout << "3 - Get position" << endl;
		cout << "4 - Set position" << endl;
		cout << "5 - Read from current position" << endl;
		cout << "6 - Write to current position" << endl;
		cout << "7 - Read from given position" << endl;
		cout << "8 - Write to given position" << endl;
		cout << "9 - Get default page capacity" << endl;
		cout << "10 - Set default page capacity" << endl;
		cout << "11 - Delete memory pool" << endl;
		cout << "0 - Quit" << endl;
		cin >> option;
		cout << endl;
		
		switch (option)
		{
			case 1: // Create memory pool
				if (true == memPoolExists)
				{
					cout << "Must delete memory pool before creating" << endl;
				}
				else
				{
					mPool = new memPool_t();
					
					if (0 == mPool)
					{
						/* TODO: handle new exception */
						return 0;
					}
					
					memPoolExists = true;
					cout << "Pool created" << endl;
				}
			break;
			
			case 2: // Get pool size
				if (true == memPoolExists)
				{
					cout << "pool size = " << mPool->GetSize() << endl;
				}
				else
				{
					cout << "Must create memory pool before getting size" << endl;
				}
			break;
			
			case 3: // Get position
				if (true == memPoolExists)
				{
					cout << "Position = " << mPool->GetPosition() << endl;
				}
				else
				{
					cout << "Must create memory pool before getting position" << endl;
				}
			break;
			
			case 4: // Set position
				if (true == memPoolExists)
				{
					bool getNewPosition = true;
					
					while(true == getNewPosition)
					{
						cout << "Enter position" << endl;
					
						cin >> position;
					
	//					if (false == mPool->SetPosition(position))
	//					{
	//						cout << "Set position failed" << endl;
	//					}
	//					else
	//					{
	//						cout << "Set position success" << endl;
	//					}

						try
						{
							getNewPosition = false;
							mPool->SetPosition(position);
						}
						catch(bool _caught)
						{
							getNewPosition = true;
							cout << "Bad position" << endl;
						}
					}
				}
				else
				{
					cout << "Must create memory pool before setting position" << endl;
				}
			break;
			
			case 5: // Read from current position
				if (true == memPoolExists)
				{
					cout << "Enter type to read" << endl;
					cout << "1 - char" << endl;
					cout << "2 - TwoBytes" << endl;
					cout << "3 - ThreeBytes" << endl;
					cout << "4 - int" << endl;
					cout << "5 - double" << endl;
					
					cin >> rwOption;
					
					switch (rwOption)
					{
						case 1:
							readResult = mPool->Read(&readChar, sizeof(char));
							cout << "readChar = " << +readChar << ", Read char returned: " << readResult << endl;
							readChar = 0;
						break;
						
						case 2:
						
						break;
						
						case 3:
						
						break;
						
						case 4:
							readResult = mPool->Read(&readInt, sizeof(int));
							cout << "readInt = " << readInt << ", Read int returned: " << readResult << endl;
							readInt = 0;
						break;
						
						case 5:
						
						break;
					}
					
				}
				else
				{
					cout << "Must create memory pool before reading" << endl;
				}
			break;
			
			case 6: // Write tp current position
				if (true == memPoolExists)
				{
					cout << "Enter type to write" << endl;
					cout << "1 - char" << endl;
					cout << "2 - TwoBytes" << endl;
					cout << "3 - ThreeBytes" << endl;
					cout << "4 - int" << endl;
					cout << "5 - double" << endl;
					
					cin >> rwOption;
					
					switch (rwOption)
					{
						case 1:
							writeResult = mPool->Write(&charVar, sizeof(char));
							cout << "Write char returned: " << writeResult << endl;
						break;
						
						case 2:
						
						break;
						
						case 3:
						
						break;
						
						case 4:
							writeResult = mPool->Write(&intVar, sizeof(int));
							cout << "Write int returned: " << writeResult << endl;
						break;
						
						case 5:
						
						break;
					}
					
				}
				else
				{
					cout << "Must create memory pool before reading" << endl;
				}
			break;
			
			
			
			
			case 11: // Delete memory pool
				if (false == memPoolExists)
				{
					cout << "Must create memory pool before deleting" << endl;
				}
				else
				{
					delete mPool;
					
					memPoolExists = false;
					
					cout << "Pool deleted" << endl;
				}
			break;
			
			case 0:
				if (true == memPoolExists)
				{
					delete mPool;
				}
				
				cont = false;
			break;
		}
	}

	/*
	int a = 1010101015;
	int b = 1010101016;
	int c = 1010101017;
	
	int x;
	int y;
	int z;

	memPool_t* mPool = new memPool_t();
	
	mPool->Write(&a, sizeof(int));
	
	mPool->Write(&b, sizeof(int));
	
	mPool->Write(&c, sizeof(int));
	
	mPool->SetPosition(0);
	
	mPool->Read(&x, sizeof(int));
	
	mPool->Read(&y, sizeof(int));
	
	mPool->Read(&z, sizeof(int));

	cout << " x = " << x << ", y = " << y << ", z = " << z << endl;
	
	delete mPool;
	*/
	
	return 0;
}
