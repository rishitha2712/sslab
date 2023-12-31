/*
============================================================================
Name : 4.c
Author : Himarishitha Kakunuri
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also. 
Date: 29th Aug, 2023.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
 
int main(){
	int fd=open("c.txt",O_RDWR|O_EXCL|O_CREAT);
	printf("%d",fd);
	if(fd<0){
		printf("File doesn't exist");
	}
	return 0;
}
