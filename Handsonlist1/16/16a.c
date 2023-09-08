/*
============================================================================
Name : 16a.c
Author : Himarishitha Kakunuri
Description : Write a program to perform mandatory locking.
	      a. Implement write lock 
Date: 29th Aug, 2023.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	struct flock lock;
	int fd=open("db",O_RDWR);
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=0;
	lock.l_pid=getpid();
	printf("Before Entering Critical Section \n");
	fcntl(fd,F_SETLKW,&lock);
	printf("Inside critical section \n");
	printf("Enter something to unlock.. \n");
	getchar();
	printf("Unlocked \n");
	lock.l_type=F_UNLCK;
	fcntl(fd,F_SETLK,&lock);
	printf("Exiting Critical Section");
	return 0;
}
