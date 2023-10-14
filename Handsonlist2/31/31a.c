/*
============================================================================
Name : 31a.c
Author : Himarishitha Kakunuri
Description : Write a program to create a semaphore and initialize value to the semaphore.
		a. create a binary semaphore
Date: 12th October, 2023.
============================================================================
*/



#include<sys/types.h> 
#include<sys/ipc.h>   
#include<sys/sem.h>   
#include<unistd.h>    
#include<stdio.h>    
#include<stdlib.h>


int main()
{
	key_t key = ftok(".",'a');
    	int id = semget(key, 1, IPC_CREAT | 0777);
    	union semun {
        	int val; 
    	} bsem;
    
    	bsem.val = 1;

    	int status = semctl(id, 0, SETVAL, bsem); 

    	if(status == -1) {
		perror("Error :");
	  	exit(0);
    	}
    	return 0;
}
