/*
============================================================================
Name : 20read.c
Author : Himarishitha Kakunuri
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 15th September, 2023.
============================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	char buf[20];
	int fd=open("myfifo",O_RDONLY);
	if(fd<0){
		perror("Failed to open pipe");
	}
	read(fd,buf,sizeof(buf));
	printf("Text from pipe: %s\n",buf);
	return 0;
}
