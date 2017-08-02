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
	unsigned int remove_flag;
	unsigned int index_to_find;
	unsigned int print_flag;
	struct app* myApp=NULL;
	struct ad* myAD=NULL;
	struct app* appFound=NULL;
	while(cont){
		printf("\n\n\nChoose option:\n");
		printf("1: Create appointment diary\n");
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
			printf("\nEnter capacity of appointment diary\n");
			scanf("%d",&cap);
			myAD=CreateAD(cap);
			if(myAD==NULL){
				printf("Not enough memory or invalid capacity\n\n");
				return 0;
			}
			else{
				printf("\nAppointment diary created\n\n");
			}
			break;
		case 2:
			/*
			Insert appointment
			*/
			if(myAD==NULL){
				printf("\nNo app diary available\n");
				break;
			}			
			printf("\nEnter appointment start time (float)\n");
			scanf("%f",&start_time);
			printf("\nEnter appointment end time (float)\n");
			scanf("%f",&end_time);
			printf("\nEnter appointment room number (unsigned int)\n");
			scanf("%d",&room);
			myApp = CreateApp(start_time,end_time,room);
			if (myApp==NULL){
				printf("\nNot enough memory or no app diary or app invalid format\n");
				return 0;
			}
			insert_app_result = InsertApp(myAD, myApp);
			switch (insert_app_result){
			case 0:
				//Appointment added succesfully
				printf("\nAppointment created and inserted\n");
				break;
			case 1:
				//no diary available
				printf("\nNo diary available\n");
				break;
			case 2:
				//no appointment available
				printf("\nNo appointment available\n");
				break;
			case 3:
				//You already have an appointment at this time
				printf("\nYou already have an appointment at this time\n");
				break;
			case 4:
				//Invalid appointment format
				printf("\nYou entered an invalid appointment format\n");
				break;
			}
			break;
		case 3:
			/*
			Remove appointment
			*/
			if(myAD==NULL){
				printf("\nNo app diary available\n");
				break;
			}			
			printf("\nEnter appointment to remove (start time(float))\n");
			scanf("%f",&start_time);
			remove_flag = RemoveApp(myAD,start_time);
			if(remove_flag==0){
				printf("\nNo app diary available or no meeting at this time");
			}
			if(remove_flag==1){
				printf("\nMeeting removed");
			}
			break;
		case 4:
			/*
			Find appointment
			*/
			printf("\n Enter start time of appointment to find (float)\n");
			scanf("%d",&index_to_find);
			appFound = FindApp(myAD,index_to_find);
			if(appFound==NULL){
				printf("Not valid appointment or no appointment found");
			}
			else{
				printf("start time: %f\n", appFound->start_time);
				printf("end time: %f\n", appFound->end_time);
				printf("room: %d\n", appFound->room);
			}
			break;
		case 5:
			/*
			Print all appointments
			*/
			if(myAD==NULL){
				printf("no valid appointment diary");
				break;
			}
			printf("\nAppointment Diary content:\n");
			for(unsigned int i=0; i < myAD->noa; ++i){
				printf("Appointment %d: ",(i+1)); 
        		printf("Start: %f, ", myAD->app_arr[i]->start_time);
				printf("End: %f, ", myAD->app_arr[i]->end_time);
				printf("Room: %d\n\n", myAD->app_arr[i]->room);
    		}
			break;
		case 6:
			/*
			Destroy appointment diary
			*/
			myAD = DestroyAD(myAD);
			break;
		}
	}
	return 0;
}