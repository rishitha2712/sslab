/*
============================================================================
Name : 23.c
Author : Himarishitha Kakunuri
Description : Write a program to print the maximum number of files can be opened within a process and size of a pipe                 (circular buffer).
Date: 10th October, 2023.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>

int main(){
	long pipe_buf,max_open;
	pipe_buf=pathconf(".",_PC_PIPE_BUF);
	max_open=sysconf(_SC_OPEN_MAX);
	printf("Size of a pipe is: %ld \n",pipe_buf);
	printf("Maximum no.of files can be opened within a process: %ld",max_open);
	return 0;
}
