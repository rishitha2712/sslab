#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int fd=creat("a.txt",O_CREAT|O_RDWR);
	printf("File Descriptor value is %d ",fd);
	return 0;
}

