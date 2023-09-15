/*
============================================================================
Name : 22w.c
Author : Himarishitha Kakunuri
Description : Write a program to write data into FIFO.
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
