/*
============================================================================
Name : 27a.c
Author : Himarishitha Kakunuri
Description : Write a program to execute ls -Rl by the following system call.
	      a. execl 
Date: 8th September, 2023.
============================================================================
*/



#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void){
	execl("/bin/ls","ls","-Rl",NULL);
	perror("Return from execl() not expected");
	exit(EXIT_FAILURE);
}
