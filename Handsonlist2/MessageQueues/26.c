/*
============================================================================
Name : 26.c
Author : Himarishitha Kakunuri
Description : Write a program to send messages to the message queue. 
Date: 10th October, 2023.
============================================================================
*/



#include <stdio.h>
#include <unistd.h>
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
	printf("Enter message: ");
	scanf(" %[^\n]", m.message);
	int size = strlen(m.message);
	msgsnd(msgid, &m, size + 1, 0);
	return 0;
}
