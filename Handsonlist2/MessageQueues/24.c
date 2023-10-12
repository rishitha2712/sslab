/*
============================================================================
Name : 24.c
Author : Himarishitha Kakunuri
Description : Write a program to create a message queue and print the key and message queue id. 
Date: 10th October, 2023.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>

int main() {
	key_t key = ftok(".", 'a');
	int msgqid = msgget(key, IPC_CREAT|IPC_EXCL|0744);
	printf("Key value: %d \n",key);
	printf("Key value in hexa decimal: 0x%0x \n",key);
	printf("Message Queue id: %d \n",msgqid);
	return 0;
}
