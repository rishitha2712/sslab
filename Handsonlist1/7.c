#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char* argv[]){
	if(argc!=3){
		printf("Useless");
		return 0;
	}
	int fd1=open(argv[1],O_RDONLY);
	int fd2=open(argv[2],O_WRONLY|O_CREAT);
	if(fd1==-1 || fd2==-1)
		printf("Can't copy");
	while(1){
		char buf;
		int ch1=read(fd1,&buf,1);
		if(ch1==0)
			break;
		int ch2=write(fd2,&buf,1);
	}
	int c1=close(fd1);
	int c2=close(fd2);
	if(c1==-1||c2==-1)
		printf("Error in closing");
	return 0;
}
	
