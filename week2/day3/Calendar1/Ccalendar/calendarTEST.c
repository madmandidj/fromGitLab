#include <stdio.h>
#include <stdlib.h>
#include "calendar.h"

int main(){
	unsigned int option;
	unsigned int cont=1;
	unsigned int cap=0;
	float start_time;
	float end_time;
	unsigned int room;
	unsigned int insert_app_result;
	struct app* myapp=NULL;
	struct ad* myad=NULL;
	while(cont){
		printf("Choose option:\n");
		printf("1: Create appointment diary\n");
		// printf("2: Create appointment\n");
		printf("2: Insert appointment\n");
		printf("3: Remove appointment\n");
		printf("4: Find appointment\n");
		printf("5: Print all appointments\n");
		printf("6: Destroy appointment diary\n");
		printf("Any another number - stop \n\n");
		scanf("%d", &option);
		switch(option){
		default:
			cont=0;
			break;
		case 1:
			/*
			Create appointment diary
			*/
			printf("Enter capacity of appointment diary\n");
			scanf("%d",&cap);
			myad=CreateAD(cap);
			if(myad==NULL){
				printf("Not enough memory\n\n");
				return 0;
			}
			else{
				printf("Appointment diary created\n\n");
			}
			break;
		case 2:
			/*
			Insert appointment
			*/
			if(myad==NULL){
				printf("\nNo app diary available\n");
				break;
			}			
			printf("Enter appointment start time (float)\n");
			scanf("%f",&start_time);
			printf("Enter appointment end time (float)\n");
			scanf("%f",&end_time);
			printf("Enter appointment room number (unsigned int)\n");
			scanf("%d",&room);
			myapp = CreateApp(start_time,end_time,room);
			if (myapp==NULL){
				printf("\nNot enough memory or no app diary\n");
				return 0;
			}
			insert_app_result = InsertApp(myad, myapp);
			switch (insert_app_result){
			case 0:
				//Appointment added succesfully
				printf("Appointment created and inserted\n");
				break;
			case 1:
				//no diary available
				break;
			case 2:
				//no appointment available
				break;
			case 3:
				//You already have an appointment at this time
				break;
			case 4:
				//Invalid appointment format
				break;
			}
			break;
		case 3:
			/*
			Remove appointment
			*/
			
			break;
		case 4:
			/*
			Find appointment
			*/
			
			break;
		case 5:
			/*
			Print all appointments
			*/
			
			break;
		case 6:
			/*
			Destroy appointment diary
			*/
			
			break;
		}
	}
	DestroyAD(myad, myapp);
	return 0;
}
