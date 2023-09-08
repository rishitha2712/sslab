/*
============================================================================
Name : 10.c
Author : Himarishitha Kakunuri
Description : Write a program to open a file with read write mode,write 10 bytes, move the file pointer by 10 bytes   		     (use lseek) and write again 10 bytes.
	      a. check the return value of lseek
	      b. open the file with od and check the empty spaces in between the data. 
Date: 29th Aug, 2023.
============================================================================
*/




#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	char buf[10];
	int fd=open("a.txt",O_CREAT|O_RDWR);
	int rd=read(0,buf,10);
	int wr=write(fd,buf,10);
	int pos=lseek(fd,10,SEEK_CUR);
	int rd1=read(0,buf,10);
	int wr1=write(fd,buf,10);
	return 0;
}
