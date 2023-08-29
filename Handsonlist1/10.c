#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	char buf[10];
	int fd=open("a.txt",O_CREAT|O_RDWR);
	int rd=read(0,buf,10);
	int wr=write(fd,buf,10);
	int pos=lseek(fd,10,SEEK_CUR);
	int rd1=read(0,buf,10);
	int wr1=write(fd,buf,10);
	return 0;
}
