#include <stdio.h>
#include "BitMap.h"

int main()
{
	int nof;
	BitMap* bM = NULL;
	BitOps bitOps[3] = {BitOn, BitOff, IsBitOn};
	int option;
	int featureNum;
	int result;
	int cont = 1;
	while(cont)
	{
		printf("\nSelect an option:\n");
		printf("1:\tCreate BitMap\n");
		printf("2:\tSet feature on\n");
		printf("3:\tSet feature off\n");
		printf("4:\tCheck feature state\n");
		printf("5:\tDestroy BitMap\n");
		printf("6:\tPrint Features\n");
		scanf("%d", &option);
		
		switch (option)
		{
			case 1:
				if (NULL != bM)
				{
					printf("BitMap already exists with %d features\n", bM->m_nof);
					break;
				}
				printf("Enter number of features\n");
				scanf("%d", &nof);
				bM = CreateBitMap(nof);
				if (NULL == bM)
				{
					printf("BitMap creation failed\n");
				}
				else
				{
					printf("BitMap created with %d features\n", bM->m_nof);
				}
				break;
			case 2:
				printf("Enter the feature to turn on\n");
				scanf("%d", &featureNum);
				result = bitOps[0](bM, featureNum);
				printf("Bit On result = %d\n", result);
				break;
			case 3:
				printf("Enter the feature to turn off\n");
				scanf("%d", &featureNum);
				result = bitOps[1](bM, featureNum);
				printf("Bit Off result = %d\n", result);
				break;
			case 4:
				printf("Enter the feature to check state\n");
				scanf("%d", &featureNum);
				result = bitOps[2](bM, featureNum);
				printf("feature State is = %d\n", result);
				break;
			case 5:
				if (NULL == bM)
				{
					printf("No existing BitMap\n");
				}
				else
				{
					DestroyBitMap(bM);
					bM = NULL; /* if this is called from within function causes segmentation faults when destroying twice */
					printf("BitMap destroyed\n");
				}
				break;	
			case 6:
				if (NULL == bM)
				{
					printf("No existing BitMap\n");
				}
				else
				{
					PrintBitMap(bM, nof);
				}
				break;	
			default:
				cont = 0;
				if (NULL == bM)
				{
					break;
				}
				else
				{
					DestroyBitMap(bM);
					bM = NULL; /* if this is called from within function causes segmentation faults when destroying twice */
				}
				break;	
		}
	}
	printf("Goodbye! :-)\n");
	return 0;
}
