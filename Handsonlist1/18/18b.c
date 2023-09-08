/*
============================================================================
Name : 18b.c
Author : Himarishitha Kakunuri
Description : Write a program to perform Record locking.
              b. Implement read lock
              Whenever you access a particular record, first lock it then modify/access to avoid race condition.
Date: 29th Aug, 2023.
============================================================================
*/




#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

struct{
        int trainno;
        int tno;
}record;

int main(){

        struct flock lock;
        int fd=open("record.txt",O_RDWR);
        int no;
        printf("Enter train number: \n");
        scanf("%d",&no);
        lock.l_type=F_RDLCK;
        lock.l_whence=SEEK_SET;
        lock.l_start=(no-1)*sizeof(record);
        lock.l_len=sizeof(record);
        lock.l_pid=getpid();

        lseek(fd,(no-1)*sizeof(record),SEEK_SET);
        read(fd,&record,sizeof(record));
        printf("Before Entering Critical Section \n");
        fcntl(fd,F_SETLKW,&lock);
        printf("Ticket number: %d \n",record.tno);
        lseek(fd,-1*sizeof(record),SEEK_CUR);
        printf("Enter to unlock.. \n");
        getchar();
        getchar();
        lock.l_type=F_UNLCK;
        fcntl(fd,F_SETLK,&lock);
        return 0;
}

