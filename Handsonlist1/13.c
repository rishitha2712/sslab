#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(){
	fd_set rfds;
	struct timeval tv;
	int retval;

	FD_ZERO(&rfds);
	FD_SET(0,&rfds);

	tv.tv_sec=10;
	tv.tv_usec=0;
	retval=select(1,&rfds,NULL,NULL,&tv);

	if(retval){
		printf("Data is available within 10 seconds \n");
	}
	else{
		printf("Data is not available within 10 seconds \n");
	}
	return 0;
}
