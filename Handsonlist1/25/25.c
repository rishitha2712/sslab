/*
============================================================================
Name : 25.c
Author : Himarishitha Kakunuri
Description : Write a program to create three child processes. The parent should wait for a particular child (use
	      waitpid system call).
Date: 8th September, 2023.
============================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int pid, pid1, pid2,status;

	if(!fork()){
		sleep(3);
		printf("I am child1 \n");
		pid=getpid();
	}

	else{

		if(!fork()){
			sleep(2);
			printf("I am child2 \n");
			pid1=getpid();
		}
		else{
			
			if(!fork()){
				sleep(5);
				printf("I am child3 \n");
				pid2=getpid();
			}
			else{
				waitpid(pid1,&status,0);
				printf("I am parent \n");
			}
		}
	}

	return 0;
}

