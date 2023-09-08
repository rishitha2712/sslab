/*
============================================================================
Name : 23.c
Author : Himarishitha Kakunuri
Description : Write a program to create a Zombie state of the running program. 
Date: 8th September, 2023.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	if(!fork()){
		printf("Child pid is: %d\n",getpid());
		printf("Exiting");
	}
	else{
		sleep(3);
		printf("I am parent");
		while(1);
	}
	return 0;
}
