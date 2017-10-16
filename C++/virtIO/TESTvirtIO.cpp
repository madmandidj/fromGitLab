#include "./virtIO_t/virtIO_t.h"
#include "./asciiIO_t/asciiIO_t.h"
#include "./binIO_t/binIO_t.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	virtIO_t* virtP;
	bool isBreakLoop = false;
	char fileOption;
	char actionOption;
	char typeOption;
	string asciiFile = "asciiFile";
	string binFile = "binFile";
	string asciiFileMode = "w+";
	string binFileMode = "w+b";
	
	
	while(1)
	{
		cout << "Select: (a)scii, (b)inary, (q)uit" << endl << endl;
	
		cin >> fileOption;
		
		isBreakLoop = false;
	
		switch (fileOption)
		{
			case 'a':
				virtP = new asciiIO_t(asciiFile, asciiFileMode);
				
				break;
			
			case 'b':
				virtP = new binIO_t(binFile, binFileMode);
			
				break;
			
			case 'q':
				if (0 != virtP)
				{
					delete virtP;
				}
				
				return 0;
		}
		
		while (!isBreakLoop)
		{
			cout << "Select: (w)rite, (r)ead, (s)et position to start, (g)et position, (o) comma operator write, (i) comma operator read, (b)reak" << endl << endl;
	
			cin >> actionOption;
		
			switch (actionOption)
			{
				case 's':
				
					virtP->SetToStartPosition();
					
					continue;
					
				case 'g':
				
					cout << "Current position: " << virtP->GetPosition() << endl << endl;
					
					continue;
					
				case 'o':
				{
					int intVal;
					
					cout << "Enter integer value to write with ',' operator" << endl << endl;
					
					cin >> intVal;
					
					binIO_t* binP = dynamic_cast<binIO_t*>(virtP);
					
					if (0 != binP)
					{
						try
						{
						
							*binP << &intVal , sizeof(int);
							
						}catch(int result){
					
							cout << " Exception: write integer with ',' operator" << endl << endl;
						}
						
					}
					else
					{
						cout << "Cannot perform ',' write with ascii file";
					}
					
					continue;
				}
				
				case 'i':
				{
					int intVal;
					
					binIO_t* binP = dynamic_cast<binIO_t*>(virtP);
					
					if (0 != binP)
					{
						try
						{
						
							*binP >> &intVal , sizeof(int);
							
						}catch(int result){
					
							cout << " Exception: read integer with ',' operator" << endl << endl;
						}
						
						cout << "int read with ',' operator: " << intVal << endl << endl;
					}
					else
					{
						cout << "Cannot perform ',' read with ascii file";
					}
					
					continue;
				}
				
				case 'b':
					delete virtP;
					
					virtP = 0;
					
					isBreakLoop = true;
					
					continue;
			}
		
			cout << "Select: (c)har, (i)nt, (f)loat, (b)reak" << endl << endl; //TODO: add option for ',' operator in binary
	
			cin >> typeOption;
			
			switch (actionOption)
			{
				case 'w':
					switch (typeOption)
					{
						case 'c':
							char c;
							
							cout << "Enter char" << endl << endl;
							
							cin >> c;
							
							try
							{
							
								*virtP << c;
								
							}catch(int result){
							
								cout << " Exception: write char" << endl << endl;
							}
							
							continue;
			
						case 'i':
							int i;
							
							cout << "Enter int" << endl << endl;
							
							cin >> i;
							
							try
							{
							
							*virtP << i;
							
							}catch(int result){
							
								cout << " Exception: write int" << endl << endl;
							}
							
							continue;
			
						case 'f':
							float f;
							
							cout << "Enter float" << endl << endl;
							
							cin >> f;
							
							try
							{
							
							*virtP << f;
							
							}catch(int result){
							
								cout << " Exception: write float" << endl << endl;
							}
							
							continue;
			
						case 'b':
							
							break;
					}
					
					break;
					
				case 'r':
					switch (typeOption)
					{
						case 'c':
							char c;
							
							try
							{
							
								*virtP >> c;
								
							}catch(int result){
							
								cout << " Exception: read char" << endl << endl;
								
								continue;
							}
							
							cout << "Char read: " << c << endl << endl;
							
							continue;
			
						case 'i':
							int i;
							try
							{
							
							*virtP >> i;
							
							}catch(int result){
							
								cout << " Exception: read int" << endl << endl;
								
								continue;
							}
							
							cout << "Integer read: " << i << endl << endl;
							
							continue;
			
						case 'f':
							float f;
							try
							{
							
							*virtP >> f;
							
							}catch(int result){
							
								cout << " Exception: read float" << endl << endl;
								
								continue;
							}
							
							cout << "Float read: " << f << endl << endl;
							break;
			
						case 'b':
		
							break;
					}
					
					break;
			}	
		}	
	}
	
	return 0;
}






