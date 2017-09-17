#include "DataGenerator.h"
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 10000






int main()
{
	size_t index;
	Record* recArr;
	Subscriber* subArr;
	Operator* operArr;
	
	recArr = malloc(ARR_SIZE * sizeof(Record));
	subArr = malloc(ARR_SIZE * sizeof(Subscriber));
	operArr = malloc(ARR_SIZE * sizeof(Operator));
			
/*	for (index = 0; index < ARR_SIZE; ++index)*/
/*	{*/
/*		GenerateSubscriber(subArr + index);*/
/*		printf("Subscriber number: %u\n", index);*/
/*		printf("imsi = \t%s\n", subArr[index].m_imsi);*/
/*		printf("uploadMB = \t%f\n", subArr[index].m_uploadMB);*/
/*		GenerateRecord(recArr + index);*/
/*		printf("Record number: %u\n", index);*/
/*		printf("imsi = \t%s\n", recArr[index].m_imsi);*/
/*		printf("operator brand = \t%s\n", recArr[index].m_operatorBrand);*/
/*		printf("operator MCCMNC = \t%s\n", recArr[index].m_operatorMCCMNC);*/
/*		printf("call date = \t%s\n", recArr[index].m_callDate);*/
/*		printf("uploadMB = \t%f\n", recArr[index].m_uploadMB);*/
/*		printf("********************\n");*/
/*	}*/

	GenerateCDRFile();
	
	
	free(recArr);
	free(subArr);
	free(operArr);
	return 0;
}


