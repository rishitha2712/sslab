#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int fd=creat("test.txt",O_CREAT);
	printf("File Descriptor value is %d ",fd);
	return 0;
}

