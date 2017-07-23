#include <stdlib.h>
#include "calendar.h"

struct ad* CreateAD(unsigned int cap){
	struct ad* myad;
	myad = malloc(sizeof(struct ad));
	if (myad==NULL){
		return NULL;
	}
	else{
		myad->app_arr = malloc(cap*sizeof(appPTR));
		if (myad->app_arr==NULL){
			free(myad);
			return NULL;
		}
		else{
			myad->cap=cap;
			myad->noa=0;
			return myad;
		}
	}
}

void DestroyAD(struct ad* myad, struct app* myapp){
	if (myad!=NULL){
		free(myad);
	}
	if (myapp!=NULL){
		free(myapp);
	}
	return;
}

struct app*	CreateApp(float start_time, float end_time, unsigned int room){
	struct app* myapp;
	myapp = malloc(sizeof(struct app));
	if (myapp==NULL){
		return NULL;
	}
	else{
		myapp->start_time = start_time;
		myapp->end_time = end_time;
		myapp->room = room;
	}
	return myapp;
}

int CheckvalidApp(struct ad* myad, struct app* myapp){
	int index;
	for(index=0;index<myad->noa;++index){	
		//Check if myapp start_time is valid	
		if((myapp->start_time >= myad->app_arr[index]->start_time) &&
			(myapp->start_time < myad->app_arr[index]->end_time)){
				return 0;
		}
		//Check if myapp end_time is valid			
		if((myapp->end_time > myad->app_arr[index]->start_time) &&
			(myapp->end_time <= myad->app_arr[index]->end_time)){
				return 0;
		}
		//Check if myapp is nested in another appointment
		if((myapp->start_time >= myad->app_arr[index]->start_time) &&
			(myapp->end_time <= myad->app_arr[index]->end_time)){
				return 0;
		}
		//Check if appointment contains another appointment
		if((myapp->start_time <= myad->app_arr[index]->start_time) &&
			(myapp->end_time >= myad->app_arr[index]->end_time)){
				return 0;
		}
	}
	return 1;
}

int InsertApp(struct ad* myad, struct app* myapp){ 
	/*
	return values: 
	0 = success 
	1 = no diary 
	2 = no appointment 
	3 = Time not available for appointment
	4 = Invalid appointment format
	*/
	if(myad==NULL){
		return 1;
	}
	if(myapp==NULL){
		return 2;
	}
	int valid_app_flag = CheckvalidApp(myad,myapp);
	if (valid_app_flag==0){
		return 3;
	}
	int index;
	int index_to_insert;
	// int valid_app_flag;
	appPTR* temp_app_arr;
	temp_app_arr = myad->app_arr;
	/*
	Insert appointment without changing capacity
	*/
	if (myad->noa < myad->cap){
		//Currently 0 appointments 
		if(myad->noa == 0){
			myad->app_arr[0] = myapp;
			++(myad->noa);
			return 0;
		}
		//Currently 1 appointments
		else if(myad->noa == 1){
			// valid_app_flag = CheckvalidApp(myad,myapp);
			// if (valid_app_flag==0){
			// 	return 3;
			// }
			 if (myapp->start_time >= myad->app_arr[0]->end_time){
				myad->app_arr[1] = myapp;
				++(myad->noa);
				return 0;
			}
			else{
				//shift 1 appointment right and enter myapp
				myad->app_arr[1] = myad->app_arr[0];
				myad->app_arr[0] = myapp;
				++(myad->noa);
				return 0;
			}
		}
		//Currently 2 or more appointments
		else{
			valid_app_flag = CheckvalidApp(myad,myapp);
			if (valid_app_flag==0){
				return 3;
			}
			for(index_to_insert=0; index_to_insert < myad->noa-1; ++index_to_insert){
				if((myapp->start_time >= myad->app_arr[index_to_insert]->end_time) &&
					(myapp->end_time < myad->app_arr[index_to_insert+1]->start_time)){
					for(index=0; index < myad->noa-index_to_insert+1 ; ++index){
						myad->app_arr[(myad->noa)-index+1] = myad->app_arr[(myad->noa)-index];
					}
					myad->app_arr[index_to_insert] = myapp;
					++(myad->noa);
					return 0;
				}
			}
		}
	}
	else{
		/*
		Change capacity and then insert appointment
		*/
		
	}
	// return XXXX; //return values: 0=success, 1=no diary, 2=no appointment, 3=Time not available for appointment
}















