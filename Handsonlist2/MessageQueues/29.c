/*
============================================================================
Name : 29.c
Author : Himarishitha Kakunuri
Description : Write a program to remove the message queue. 
Date: 11th October, 2023.
============================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
	key_t key = ftok(".", 'b');
	int msgid = msgget(key, 0);
	
	if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        	perror("msgctl");
        	exit(1);
	}
	printf("Message queue removed successfully.\n");
	return 0;
}

