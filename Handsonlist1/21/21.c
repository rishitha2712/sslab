/*
============================================================================
Name : 21.c
Author : Himarishitha Kakunuri
Description : Write a program, call fork and print the parent and child process id.
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
		printf("Child process id: %d\n",getpid());
	}
	else{
		printf("Parent process id: %d \n",getpid());
	}
	return 0;
}
