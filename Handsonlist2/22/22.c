/*
============================================================================
Name : 22.c
Author : Himarishitha Kakunuri
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select system call with  		     FIFO. 
Date: 15th September, 2023.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(void){
	fd_set rfds;
	struct timeval tv;
	int retval;
	char buf[50];

	int fd=open("myfifo",O_RDONLY);

	FD_ZERO(&rfds);
	FD_SET(fd,&rfds);

	tv.tv_sec=10;
	tv.tv_usec=0;
	retval=select(fd+1,&rfds,NULL,NULL,&tv);

	if(retval){
		printf("Data is available within 10 seconds \n");
	}
	else{
		printf("Data is not available within 10 seconds \n");
		exit(0);
	}
	read(fd,buf,sizeof(buf));
	printf("Text from pipe: %s\n",buf);
}

