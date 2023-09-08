/*
============================================================================
Name : 3.c
Author : Himarishitha Kakunuri
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call. 
Date: 29th Aug, 2023.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int fd=creat("test.txt",O_CREAT);
	printf("File Descriptor value is %d ",fd);
	return 0;
}

