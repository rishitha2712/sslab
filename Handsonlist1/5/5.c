/*
============================================================================
Name : 5.c
Author : Himarishitha Kakunuri
Description : Write a program to create five new files with infinite loop. 
	      Execute the program in background and check the file descriptor table at /proc/pid/fd. 
Date: 29th Aug, 2023.
============================================================================
*/




#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int fd1=creat("new1",O_CREAT);
	int fd2=creat("new2",O_CREAT);
	int fd3=creat("new3",O_CREAT);
	int fd4=creat("new4",O_CREAT);
	int fd5=creat("new5",O_CREAT);
	while(1){
	}
	return 0;
}
