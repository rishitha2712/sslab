/*
============================================================================
Name : 30.c
Author : Himarishitha Kakunuri
Description : Write a program to create a shared memory.
		a. write some data to the shared memory
		b. attach with O_RDONLY and check whether you are able to overwrite.
		c. detach the shared memory
		d. remove the shared memory
Date: 12th October, 2023.
============================================================================
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
   
       	key_t key = ftok(".", 'a');
    	int shmid = shmget(key, 1024, IPC_CREAT | 0744);

	char *shm=shmat(shmid,0,SHM_RDONLY);
       
	if (shm == (char *)-1) {
        	perror("shmat");
        	exit(1);
    	}


	printf("Enter text:");
        scanf("%[^\n]",shm);


        strcpy(shm, "Trying to overwrite");
        if (shmdt(shm) == -1) {
   	     perror("shmdt");
	     exit(1);
    	}
       
        if (shmctl(shmid, IPC_RMID, NULL) == -1) {
	       perror("shmctl");
	       exit(1);
    	}
       
        return 0;

}

