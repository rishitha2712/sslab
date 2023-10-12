/*
============================================================================
Name : 25.c
Author : Himarishitha Kakunuri
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
	a. access permission
	b. uid, gid
	c. time of last message sent and received
	d. time of last change in the message queue
	e. size of the queue
	f. number of messages in the queue
	g. maximum number of bytes allowed
	h. pid of the msgsnd and msgrcv 
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

int main () {

	struct ipc_perm msg_perm; 
	struct msqid_ds mq;
	struct msginfo info;

	key_t key= ftok (".", 'a');
	int msgid = msgget (key, 0);
	msgctl (msgid, IPC_STAT, &mq);
	
	printf ("Access Permission: %03o\n", mq.msg_perm.mode & 0777);
	printf ("UID of owner: %d\n", msg_perm.uid); 
	printf ("GID of owner: %d\n", msg_perm.gid);
	printf ("UID of creator: %d\n", msg_perm.cuid); 
	printf ("GID of creator: %d\n", msg_perm.cgid);
	printf ("Time of last message sent: %s", ctime (&mq.msg_stime));
	printf ("Time of last message received: %s", ctime (&mq.msg_rtime)); 
	printf ("Time of last change in message queue: %s", ctime (&mq.msg_ctime));
	printf ("Size of message queue: %lu\n", mq.msg_cbytes);
	printf ("Current number of messages in queue: %lu\n", mq.msg_qnum);
	printf ("Maximum number of bytes allowed in queue: %lu\n", mq.msg_qbytes);
	printf ("PID of last message sent: %d\n", mq.msg_lspid);
       	printf ("PID of last message received: %d\n", mq.msg_lrpid);
	return 0;
}
