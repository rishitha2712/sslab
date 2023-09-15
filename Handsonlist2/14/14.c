/*
============================================================================
Name : 14.c
Author : Himarishitha Kakunuri
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor. 
Date: 15th September, 2023.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>

int main(){
	
	int fd[2];
	char buf[20];
	pipe(fd);

	write(fd[1],"Hi I am rishitha\n",17);
	read(fd[0],buf,sizeof(buf));

	printf("Read from pipe: %s \n",buf);
	return 0;
}
