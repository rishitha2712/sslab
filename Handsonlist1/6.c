#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	char buf[1024];
	int rd=read(0,buf,1024);
	int wr=write(1,buf,rd);
	return 0;
}

