/*
============================================================================
Name : 20write.c
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
	int fd=open("myfifo",O_WRONLY);
	if(fd<0){
		perror("Error in opening pipe");
	}
	printf("Enter text: ");
	scanf("%[^\n]",buf);
	write(fd,buf,sizeof(buf));
	return 0;
}
