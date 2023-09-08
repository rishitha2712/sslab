/*
============================================================================
Name : 20.c
Author : Himarishitha Kakunuri
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 8th September, 2023.
============================================================================
*/



#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/resource.h>


int main(){

	int pid = getpid();
	printf("PID: %d\n",pid);

	printf("Current Priority: %d\n",getpriority(PRIO_PROCESS,0));

	nice(5);
	
	printf("Updated Priority: %d\n",getpriority(PRIO_PROCESS,0));

}
