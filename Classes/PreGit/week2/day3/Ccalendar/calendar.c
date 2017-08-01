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
	int index;
	int ind_to_insert;
	int valid_app_flag;
	if(myad==NULL){
		return 1;
	}
	if(myapp==NULL){
		return 2;
	}
	//Insert appointment without changing capacity
	if (myad->noa < myad->cap){
		//If no appointments yet
		if(myad->noa == 0){
			myad->app_arr[0] = myapp;
			++(myad->noa);
			return 0;
		}
		//If 1 appointment
		if(myad->noa == 1){
			valid_app_flag = CheckvalidApp(myad,myapp);
			if (valid_app_flag==0){
				return 3;
			}
			if (myapp->start_time >= myad->app_arr[0]->end_time){
				myad->app_arr[0] = myapp;
				++(myad->noa);
				return 0;
			}
			else{
				//shift 1 appointment right and enter myapp
			}
		}
		else{
			valid_app_flag = CheckvalidApp(myad,myapp);
			if (valid_app_flag==0){
				return 3;
			}
			//If reached here then myapp is valid. Now find correct index
			for(index=0;index<myad->noa-1;++index){
				if((myapp->start_time >= myad->app_arr[index]->end_time) &&
					(myapp->start_time < myad->app_arr[index]->end_time)){
					
			}
		}
	}
	return XXXX; //return values: 0=success, 1=no diary, 2=no appointment, 3=Time not available for appointment
}















