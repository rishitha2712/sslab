/*
============================================================================
Name : 15.c
Author : Himarishitha Kakunuri
Description : Write a simple program to send some data from parent to the child process. 
Date: 15th September, 2023.
============================================================================
*/




#include <unistd.h>
#include <stdio.h>

int main(){

	int fd[2];
	char buf[20];
	pipe(fd);
	if(!fork()){
		close(fd[1]);
		read(fd[0],buf,sizeof(buf));
		printf("Message recieved from parent: %s \n",buf);
	}
	else{
		close(fd[0]);
		printf("Enter message to child: \n");
		scanf("%[^\n]",buf);
		write(fd[1],buf,sizeof(buf));
	}
	return 0;
}
