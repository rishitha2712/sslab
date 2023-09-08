/*
============================================================================
Name : 24.c
Author : Himarishitha Kakunuri
Description : Write a program to create an orphan process. 
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
		sleep(20);
		printf("I am child");
	}
	else{
		printf("I am parent with pid: %d\n",getpid());
	}
	return 0;
}
