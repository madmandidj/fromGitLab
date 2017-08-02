#ifndef STRINGH_H
#define STRINGH_H
#define MY_STRING_CAPACITY 100
#define END_OF_STRING 0
#define FAIL_VAL 0
#define ERROR_VAL -1
#define SUCCES_VAL 1
#define ASCI_MINUS 45
/*
Reverses the order of characters in a string
Input:      string 
Output:     '1' if reverse succeeded, '-1' if error 
Error:      str = NULL will return '-1'
*/
int ReverseString(char *str);

/*
Checks if string is a palindrome
Input:      string 
Output:     '1' if is palindrome, '0' if not, '-1' if error
Error:      str = NULL will return '-1'
*/
int IsPalindrome(char *str);

/*
Converts a string to integer
Input:      string (predictable behaviour for –2147483648 < str < 2147483647)
Output:     integer result if succeeded, '0' if failed
Error:      ***If str does not point to a valid C-string, or if the converted value would be 
            out of the range of values representable by an int, it causes undefined behavior.
*/
// int myAtoI(char *str, int *num);
int my_atoi(char *str);

/*
Converts an integer to string
Input:      str should be an array long enough to contain any possible value: (sizeof(int)*8+1). 
            Base != 10 then value is considered unsigned. Base == 10 && value < 0 then resulting string is preceded by '-'
Output:     string result if succeeded, '0' if failed
Error:      ?
*/
char* my_itoa(int value, char *str, int base);
#endif