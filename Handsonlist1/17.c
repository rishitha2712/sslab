#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){

	struct{
		int t_no;
	}db;

        struct flock lock;
        int fd=open("db",O_RDWR);
	read(fd,&db,sizeof(db));
        lock.l_type=F_WRLCK;
        lock.l_whence=SEEK_SET;
        lock.l_start=0;
        lock.l_len=0;
        lock.l_pid=getpid();
        printf("Before Entering Critical Section \n");
        fcntl(fd,F_SETLKW,&lock);
	printf("Current Ticket number: %d \n",db.t_no);
	db.t_no++;
	lseek(fd,0L,SEEK_SET);
        printf("Inside critical section \n");
        printf("Enter something to unlock.. \n");
	write(fd,&db,sizeof(db));
        getchar();
        printf("Unlocked \n");
        lock.l_type=F_UNLCK;
        fcntl(fd,F_SETLK,&lock);
	printf("Exiting Critical Section");
        return 0;
}

