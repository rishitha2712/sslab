/*
============================================================================
Name : 29.c
Author : Himarishitha Kakunuri
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR). 
Date: 8th September, 2023.
============================================================================
*/





#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main(void){
	pid_t pid;
	int ch;
	pid=getpid();
	int policy,newpolicy;
	struct sched_param sp;
	policy=sched_getscheduler(pid);
	
	switch(policy){
		case SCHED_FIFO:
			printf("Current Scheduling Policy is: FIFO\n");
			break;
		case SCHED_RR:
			printf("Current Scheduling Policy is: Round Robin\n");
			break;
		case SCHED_OTHER:
			printf("Current Scheduling Policy is: SCHED_OTHER\n");
			break;
		default:
			printf("Unknown\n");
	}
	printf("Enter choice to modify scheduling policy to:\n 1.FIFO \n 2.RR \n");
	scanf("%d",&ch);
	sp.sched_priority=99;
	switch(ch){
                case 1:
                        sched_setscheduler(pid,SCHED_FIFO,&sp);
                        break;
                case 2:
                        sched_setscheduler(pid,SCHED_RR,&sp);
                        break;
                default:
                        printf("Wrong Choice\n");
        }
	newpolicy=sched_getscheduler(pid);
	switch(newpolicy){
                case SCHED_FIFO:
                        printf("Current Scheduling Policy is: FIFO\n");
                        break;
                case SCHED_RR:
                        printf("Current Scheduling Policy is: Round Robin\n");
                        break;
                case SCHED_OTHER:
                        printf("Current Scheduling Policy is: SCHED_OTHER\n");
                        break;
                default:
                        printf("Unknown\n");
        }


}
