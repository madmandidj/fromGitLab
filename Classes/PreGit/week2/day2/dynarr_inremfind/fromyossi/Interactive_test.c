
#include <stdio.h>

void Insert(...)	{}
void Find(...)		{}
void Remove(...)	{}

int main()
{
	int cont = 1;			// trigger to stop loop	
	unsigned int option;
	
	while (cont) {
		printf("Choose option: \n");
		printf("1: Insert  \n");
		printf("2: Find    \n");
		printf("3: Remove  \n");
		printf("Any another number - stop \n");

		scanf("%d", &option);
		switch (option) {
			case 1:
				int Insert(DA* arr, int* numPtr, int index );	break;
			case 2:
				int* Find(DA* arr, int num);					break;
			case 3:
				int Remove(DA* arr, int num);					break;

			default: cont = 0;	break;
		}
	}

	return 0;
}

