#include "String_t.h"
#include <stdio.h>
#include <string.h>


static void DisplayUI()
{
	cout << "\n\nSelect an option:\n";
	cout << "1: default CTOR\t\t2: copy CTOR\n";
	cout << "3: char* CTOR\t\t4: = operator\n";
	cout << "5: Length\t\t6: Set\n";
	cout << "7: Get\t\t\t8: Compare\n";
	cout << "9: ToLower\t\t10: ToUpper\n";
	cout << "11: Prepend char*\t12: Prepend String_t\n";
	cout << "13: += char*\t\t14: += String_t\n";
	cout << "15: > char*\t\t16: Contains char*\n";
	cout << "17: Contains String_t\t18: IthChar\n";
	cout << "19: []\t\t\t20: >> / <<\n";
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
	
	while(cont)
	{

		DisplayUI();
		
		option = GetUserOption();
		
		switch(option)
		{
			case 1: /* Default constructor */
			{
				String_t str_t1;
				
				cout << "\nDefault constructor = empty string" << str_t1 << "\n";
				
				break;
			}
			
				
			case 2: /* Copy constructor */
			{
				String_t str_t1 = "Good Morning Bareket Copy constructor";
				
				String_t str_t2 = str_t1;
				
				cout << "\nString is: " << str_t2 << "\n";
				
				break;
			}
			
			
			case 3: /* char* constructor */
			{
				String_t str_t1("Good Morning Bareket char* constructor");
				
				cout << "\nString is: " << str_t1 << "\n";
				
				break;
			}
			
			
			case 4: /* assignment operator */
			{
				String_t str_t1("Good Morning Bareket assignment operator");
				String_t str_t2;
				
				str_t2 = str_t1;
				
				cout << "\nString is: " << str_t2 << "\n";
				
				break;
			}
			
			
			case 5: /* Length */
			{
				char input[128];
				
				cout << "Please enter string for Length\n";
				
				cin >> input; 
				
				String_t str_t1(input);
				
				cout << "String: \"" << str_t1 << "\", length = " << str_t1.Length() << "\n";
				
				break;
			}
			
			
			case 6: /* Set */
			{
				char input[128];
				String_t str_t1;
				
				cout << "Please enter string for Set\n";
				
				cin >> input; 
				
				str_t1.Set(input);
				
				cout << "String is: \"" << str_t1 << "\"\n";
				
				break;
			}
			
			
			case 7: /* Get */
			{
				char input[128];
				String_t str_t1;
				char* str;
				
				cout << "Please enter string for Get\n";
				
				cin >> input; 
				
				str_t1.Set(input);
				str = (char*)str_t1.Get();
				
				cout << "String is: \"" << str << "\"\n";
				
				break;
			}
			
			
			case 8: /* Compare */
			{
				char input1[128];
				char input2[128];

				
				cout << "Please enter 2 strings for Compare\n";
				
				cin >> input1 >> input2; 
				
				String_t str_t1 = input1;
				String_t str_t2 = input2;
				
				cout << "String compare result is: " << str_t1.Compare(str_t2) << "\n";
				
				break;
			}		
			
			
			case 9: /* Convert To Lower Case */
			{
				char input1[128];

				cout << "Please enter string to convert to lower case\n";
				
				cin >> input1; 
				
				String_t str_t1 = input1;
				
				str_t1.ToLower();
				
				cout << "Lower case string: " << str_t1 << "\n";
				
				break;
			}	
			
			
			case 10: /* Convert To Upper Case */
			{
				char input1[128];

				cout << "Please enter string to convert to upper case\n";
				
				cin >> input1; 
				
				String_t str_t1 = input1;
				
				str_t1.ToUpper();
				
				cout << "Upper case string: " << str_t1 << "\n";
				
				break;
			}
			
			
			case 11: /* Prepend char* */
			{
				String_t str_t1 = "Eyal";
				char input1[128];
				
				cout << "Please enter string to prepend (from char*)\n";
				
				cin >> input1; 
				
				cout << "Before: " << str_t1 << ", ";
				
				str_t1.Prepend(input1);
				
				cout << "After: " << str_t1 << "\n";
				
				break;
			}	
			
			
			case 12: /* Prepend String_t */
			{
				String_t str_t1 = "Eyal";
				char input1[128];
				
				cout << "Please enter string to prepend (from String_t)\n";
				
				cin >> input1; 
				
				String_t str_t2 = input1;
				
				cout << "Before: " << str_t1 << ", ";
				
				str_t1.Prepend(str_t2);
				
				cout << "After: " << str_t1 << "\n";
				
				break;
			}	
			
			
			case 13: /* Append operator char* */
			{
				String_t str_t1 = "Eyal";
				char input1[128];
				
				cout << "Please enter string to append (from char*)\n";
				
				cin >> input1; 
				
				cout << "Before: " << str_t1 << ", ";
				
				str_t1 += input1;
				
				cout << "After: " << str_t1 << "\n";
				
				break;
			}	
			
			
			case 14: /* Append operator String_t */
			{
				String_t str_t1 = "Eyal";
				char input1[128];
				
				cout << "Please enter string to append (from String_t)\n";
				
				cin >> input1; 
				
				String_t str_t2 = input1;
				
				cout << "Before: " << str_t1 << ", ";
				
				str_t1 += str_t2;
				
				cout << "After: " << str_t1 << "\n";
				
				break;
			}
			
			
			case 15: /* Larger than operator char* */
			{
				String_t str_t1 = "Eyal";
				char input1[128];
				bool result;
				
				cout << "Please enter string to check if larger than \"Eyal\" (from char*)\n";
				
				cin >> input1; 
				
				result = str_t1 > input1;
				
				cout << " Eyal > input = " << result << "\n";
				
				break;
			}
			
			
			case 16: /* Contains char* */
			{
				char input1[128];
				char input2[128];
				
				cout << "Please enter container and contained (char*) \n";
				
				cin >> input1 >> input2; 
				
				String_t str_t1 = input1;
				
				cout << "Contained result = " << str_t1.Contains(input2) << "\n";
				
				break;
			}
			
			
			case 17: /* Contains String_t */
			{
				char input1[128];
				char input2[128];
				
				cout << "Please enter container and contained (String_t) \n";
				
				cin >> input1 >> input2; 
				
				String_t str_t1 = input1;
				String_t str_t2 = input2;
				
				cout << "Contained result = " << str_t1.Contains(str_t2) << "\n";
				
				break;
			}
			
			
			case 18: /* Get Ith Char */
			{
				char input1[128];
				size_t i;
				
				cout << "Please enter string and char index to get\n";
				
				cin >> input1 >> i; 
				
				String_t str_t1 = input1;
				
				cout << "i'th char = " << str_t1.IthChar(i) << "\n";
				
				break;
			}
			
			
			case 19: /* Get Ith Char operator */
			{
				char input1[128];
				size_t i;
				
				cout << "Please enter string and char index to get (operator)\n";
				
				cin >> input1 >> i; 
				
				String_t str_t1 = input1;
				
				cout << "i'th char = " << str_t1[i] << "\n";
				
				break;
			}
			
			
			case 20: /* Input/Output operators */
			{
				String_t str_t1;
				
				cout << "Please enter string to check Input/Output operators\n";
				
				cin >> str_t1; 
				
				cout << "Output operator string: \"" << str_t1 << "\"\n";
				
				break;
			}	
			
				
			case 0:
			{
				cont = 0;
			}
			
			
			default:
				continue;
		}
	}
	
	
	return 0;
}









