#include <stdio.h>
#include <stdlib.h>
#include "NewCalendar.h"

int main(){
	int option;
	int cont=1;
	int cap=0;
	float start_time;
	float end_time;
	int room;
	int insert_app_result;
	int remove_flag;
	int index_to_find;
	int i;
	App* myApp = NULL;
	AD* myAD = NULL;
	App* appFound = NULL;
	myAD = ReadAppsFromFile();
	if (NULL != myAD)
	{
		printf("Appointment diary loaded from file\n");
	}
	while(cont){
		printf("\nChoose option:\n");
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
			PrintAppsToFile(myAD);
			myAD = DestroyAD(myAD);
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
				printf("\nNo App diary available\n");
				break;
			}			
			printf("\nEnter appointment start time (float)\n");
			scanf("%f",&start_time);
			printf("\nEnter appointment end time (float)\n");
			scanf("%f",&end_time);
			printf("\nEnter appointment room number (int)\n");
			scanf("%d",&room);
			myApp = CreateApp(start_time,end_time,room);
			if (myApp==NULL){
				printf("\nNot enough memory or no App diary or App invalid format\n");
				return 0;
			}
			insert_app_result = InsertApp(myAD, myApp);
			switch (insert_app_result){
			case 0:
				printf("\nAppointment created and inserted\n");
				break;
			case 1:
				printf("\nNo diary available\n");
				break;
			case 2:
				printf("\nNo appointment available\n");
				break;
			case 3:
				printf("\nYou already have an appointment at this time\n");
				break;
			case 4:
				printf("\nYou entered an invalid appointment format\n");
				break;
			}
			break;
		case 3:
			/*
			Remove appointment
			*/
			if(myAD==NULL){
				printf("\nNo App diary available\n");
				break;
			}			
			printf("\nEnter appointment to remove (start time(float))\n");
			scanf("%f",&start_time);
			remove_flag = RemoveApp(myAD,start_time);
			if(remove_flag==0){
				printf("\nNo App diary available or no meeting at this time");
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
				printf("start time: %f\n", appFound->m_startTime);
				printf("end time: %f\n", appFound->m_endTime);
				printf("room: %d\n", appFound->m_room);
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
			for(i = 0; i < myAD->m_nOA; ++i){
				printf("Appointment %d: ",(i+1)); 
        		printf("Start: %f, ", myAD->m_appArr[i]->m_startTime);
				printf("End: %f, ", myAD->m_appArr[i]->m_endTime);
				printf("Room: %d\n\n", myAD->m_appArr[i]->m_room);
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
