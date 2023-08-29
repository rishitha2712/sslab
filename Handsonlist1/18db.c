#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main(){
	struct{
		int trainno;
		int tno;
	}record[3];	
	
	int fd=open("record.txt",O_RDWR);
	
	for(int i=0;i<3;i++){
		record[i].trainno=i+1;
		record[i].tno=0;
	}

        write(fd,record,sizeof(record));

	close(fd);

	return 0;
}
