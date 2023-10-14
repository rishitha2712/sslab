/*
============================================================================
Name : 31b.c
Author : Himarishitha Kakunuri
Description : Write a program to create a semaphore and initialize value to the semaphore.
		b. create a counting semaphore 
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
	key_t key = ftok(".",'b');
      	int id = semget(key, 1, IPC_CREAT | 0777);
    
      	union semun {
		int val; 
      	} csem;
    
      	csem.val = 3;

      	int status = semctl(id, 0, SETVAL, csem);

      	if(status == -1) {
              perror("Error :");
	      exit(0);
      	}
      	return 0;
}
