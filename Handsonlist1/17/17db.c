/*
============================================================================
Name : 17db.c
Author : Himarishitha Kakunuri
Description : Write a program to open a file, store a ticket number and exit. 
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
	int fd=open("db",O_RDWR);
	struct{
		int t_no;
	}db;
	db.t_no=20;
	write(fd,&db,sizeof(db));

	close(fd);
	return 0;
}
