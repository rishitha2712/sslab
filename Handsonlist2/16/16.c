/*
============================================================================
Name : 16.c
Author : Himarishitha Kakunuri
Description : Write a program to send and receive data from parent to child vice versa. Use two way communication. 
Date: 15th September, 2023.
============================================================================
*/



#include <unistd.h>
#include <stdio.h>

int main(){

	int fd1[2],fd2[2];
	char buf1[20],buf2[20];
	pipe(fd1);
	pipe(fd2);
	if(!fork()){
		close(fd1[1]);
		read(fd1[0],buf1,sizeof(buf1));
		printf("Message recieved from parent: %s \n",buf1);
		close(fd2[0]);
		printf("Enter message to parent:");
		scanf("%[^\n]",buf2);
		write(fd2[1],buf2,sizeof(buf2));
	}
	else{
		close(fd1[0]);
		printf("Enter message to child:");
		scanf("%[^\n]",buf1);
		write(fd1[1],buf1,sizeof(buf1));
		close(fd2[1]);
		read(fd2[0],buf2,sizeof(buf2));
		printf("Message received from child: %s \n",buf2);
	}
	return 0;
}

