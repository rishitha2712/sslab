/*
============================================================================
Name : 28.c
Author : Himarishitha Kakunuri
Description : Write a program to change the exiting message queue permission. 
Date: 11th October, 2023.
============================================================================
*/




#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    
    struct msqid_ds msq;

    key_t  key = ftok(".", 'a');
    int msqid = msgget(key, 0666 | IPC_CREAT);
    msgctl(msqid, IPC_STAT, &msq);
    msq.msg_perm.mode = 0644;
    msgctl(msqid, IPC_SET, &msq);

    printf("Message queue permissions changed successfully.\n");

    return 0;
}

