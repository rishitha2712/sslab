#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
	int fd=open("db",O_RDONLY);	
	int flags=fcntl(fd,F_GETFL);
	if(flags==-1){
		exit(0);
	}
	if(flags & O_SYNC){
		printf("Synchronized");
	}
	int m=flags&O_ACCMODE;
	if(m == O_RDONLY){
		printf("File mode is read only");
	}
	else if(m == O_WRONLY || m == O_RDWR){
		printf("File is writable");
	}
	return 0;}
