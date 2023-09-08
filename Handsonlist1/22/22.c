/*
============================================================================
Name : 22.c
Author : Himarishitha Kakunuri
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
	      parent processes. Check output of the file. 
Date: 8th September, 2023.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int fd=open("sample.txt",O_RDWR);
	if(!fork()){
		write(fd,"Hi I am child \n",15);
	}
	else{
		write(fd,"Written by Parent \n",19);
	}
	return 0;
}
