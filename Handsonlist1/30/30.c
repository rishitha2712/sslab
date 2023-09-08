/*
============================================================================
Name : 30.c
Author : Himarishitha Kakunuri
Description : Write a program to run a script at a specific time using a Daemon process. 
Date: 8th September, 2023.
============================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(){

	struct tm dt;
	dt.tm_hour=19;
	dt.tm_min=57;
	dt.tm_sec=0;
	dt.tm_mday=8;
	dt.tm_mon=8;
	dt.tm_year=2023-1900;

	time_t now;
	struct tm *ct;
	time(&now);
	ct=localtime(&now);
	time_t tdelay=mktime(&dt)-mktime(ct);
	

	if(tdelay<=0){
		printf("Invalid..Set future time only \n");
	}

	if(!fork()){
		setsid();
		sleep(mktime(&dt)-mktime(ct));
		printf("Deamon Process \n");
		execl("/bin/sh","sh","/home/himarishitha/SSLab/Handsonlist1/a.sh",NULL);
	}

	else{
		printf("Parent process \n");
	}
	return 0;
}
