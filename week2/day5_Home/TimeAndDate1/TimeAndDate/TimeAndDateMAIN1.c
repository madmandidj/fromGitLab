#include <stdio.h>
#include <time.h>
#include "TimeAndDateMAIN1.h"

int main(){
    time_t time_date;
    struct tm* current_time;
    time_date = time(0);
    current_time = localtime(&time_date);
    printf("")
    return 0;
}