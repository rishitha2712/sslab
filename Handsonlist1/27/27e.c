/*
============================================================================
Name : 27e.c
Author : Himarishitha Kakunuri
Description : Write a program to execute ls -Rl by the following system call.
              e. execvp 
Date: 8th September, 2023.
============================================================================
*/




#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
 	char *command = "ls";
 	char *args[] = {"ls", "-Rl", NULL};
 	execvp(command,args);
 	perror("execvp() : ");
 	exit(EXIT_FAILURE);
}
