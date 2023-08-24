#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int fd=open("codefile",O_RDONLY);
	char buf[100];
	while(1){
		int chr=read(fd,&buf,100);
		if(chr==0)
			break;
		int chw=write(1,&buf,chr);
	}
	int fc=close(fd);
}
