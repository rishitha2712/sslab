/*
============================================================================
Name : 19.c
Author : Himarishitha Kakunuri
Description : Create a FIFO file by
	      a. mknod system call
	      b. mkfifo library function 
Date: 15th September, 2023.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int p=mknod("fifo1",S_IFIFO,0);
	if(p<0){
		perror("Failed to create pipe");
	}
	int f=mkfifo("fifo2",S_IFIFO);
	if(f<0){
		perror("Failed to create pipe");
	}
	return 0;
}
