/*
============================================================================
Name : 27.c
Author : Himarishitha Kakunuri
Description : Write a program to receive messages from the message queue. 
Date: 10th October, 2023.
============================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

int main() {
	struct msg {
		long int m_type;
		char message[100];
	} m;
	key_t key = ftok(".", 'a');
	int msgid = msgget(key, 0);
	printf("Enter message type: ");
	scanf("%ld", &m.m_type);
	msgrcv(msgid, &m, sizeof(m.message), m.m_type,IPC_NOWAIT);
	printf("Message type: %ld\n", m.m_type);
	printf("Received Message: %s\n",m.message);
	return 0;
}
