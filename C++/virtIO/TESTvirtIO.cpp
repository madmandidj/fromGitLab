#include "./virtIO_t/virtIO_t.h"
#include "./asciiIO_t/asciiIO_t.h"
#include "./binIO_t/binIO_t.h"
#include <iostream>
#include <string>

using namespace std;



int main()
{
	/*
	select ascii / binary
	select write / read / break 
	select int / float /
	*/
	virtIO_t* virtP;
	bool cont = true;
	bool isBreakLoop = false;
	char fileOption;
	char actionOption;
	char typeOption;
	string asciiFile = "asciiFile";
	string binFile = "binFile";
	string fileMode = "w+";
	
	
	while(1)
	{
		cout << "Select: (a)scii, (b)inary, (q)uit" << endl;
	
		cin >> fileOption;
		
		isBreakLoop = false;
	
		switch (fileOption)
		{
			case 'a':
				virtP = new asciiIO_t(asciiFile, fileMode);
				
				break;
			
			case 'b':
				virtP = new binIO_t(binFile, fileMode);
			
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
			cout << "Select: (w)rite, (r)ead, (s)et start position, (b)reak" << endl;
	
			cin >> actionOption;
		
			switch (actionOption)
			{
				case 's':
					//TODO: call set start position
					virtP->SetToStartPosition();
					continue;
				
				case 'b':
					delete virtP;
					
					virtP = 0;
					
					isBreakLoop = true;
					
					continue;
			}
		
			cout << "Select: (c)har, (i)nt, (f)loat, (b)reak" << endl; //TODO: add option for ',' operator in binary
	
			cin >> typeOption;
			
			switch (actionOption)
			{
				case 'w':
					switch (typeOption)
					{
						case 'c':
							char c;
							
							cout << "Enter char" << endl;
							
							cin >> c;
							
							*virtP << c;
							
							continue;
			
						case 'i':
							int i;
							
							cout << "Enter int" << endl;
							
							cin >> i;
							
							*virtP << i;
							
							continue;
			
						case 'f':
							int f;
							
							cout << "Enter float" << endl;
							
							cin >> f;
							
							*virtP << f;
							break;
			
						case 'b':
							
							break;
					}
					
					break;
					
				case 'r':
					switch (typeOption)
					{
						case 'c':
							char c;
							
							*virtP >> c;
							
							cout << "Char read: " << c << endl;
							
							continue;
			
						case 'i':
							int i;
							
							*virtP >> i;
							
							cout << "Integer read: " << i << endl;
							
							continue;
			
						case 'f':
							int f;
							
							*virtP >> f;
							
							cout << "Float read: " << f << endl;
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






