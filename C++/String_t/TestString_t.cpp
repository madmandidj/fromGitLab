#include "String_t.h"
#include <stdio.h>
#include <string.h>


static void DisplayUI()
{
	cout << "Select an option:\n";
	cout << "1: default constructor\n";
	cout << "2: copy constructor\n";
	cout << "3: char* constructor\n";
	cout << "4: assignment operator\n";
	cout << "5: Length\n";
	cout << "6: SetString\n";
	cout << "7: GetString\n";
	cout << "8: Compare\n";
	cout << "9: ConvertToLowerCase\n";
	cout << "10: ConvertToUpperCase\n";
	cout << "11: Prepend char*\n";
	cout << "12: Prepend String_t\n";
	cout << "13: Append operator char*\n";
	cout << "14: Append operator String_t\n";
	cout << "15: LargerThan operator\n";
	cout << "16: Contains char*\n";
	cout << "17: Contains String_t\n";
	cout << "18: GetIthChar\n";
	cout << "19: GetIthChar operator\n";
	cout << "20: Screen print operator\n";
	cout << "21: Get input operator\n";
	cout << "0: Quit and have a nice day! :-)\n";
	
	return;
}



static unsigned int GetUserOption()
{
	unsigned int option;
	cin >> option;
	
	return option;
}




int main()
{
	unsigned int option;
	unsigned int cont = 1;
	String_t str_t1;
	String_t str_t2;
	
	while(cont)
	{

		DisplayUI();
		
		option = GetUserOption();
		
		switch(option)
		{
			case 1: /* Default constructor */
			{
				String_t str_t3;
				
				cout << "\nDefault constructor = empty string" << str_t3 << "\n";
				
				break;
			}
				
			case 2: /* Copy constructor */
			{
				String_t str_t3 = "Good Morning Bareket Copy constructor";
				
				String_t str_t4 = str_t3;
				
				cout << "\nString is: " << str_t4 << "\n";
				
				break;
			}
			
			case 3: /* char* constructor */
			{
				String_t str_t3("Good Morning Bareket char* constructor");
				
				cout << "\nString is: " << str_t3 << "\n";
				
				break;
			}
				
			default:
				cont = 0;
				break;
		}
	}
	
	
	
	
	return 0;
}









