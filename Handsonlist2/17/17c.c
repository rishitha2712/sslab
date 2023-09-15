/*
============================================================================
Name : 17c.c
Author : Himarishitha Kakunuri
Description : Write a program to execute ls -l | wc.
	      c. use fcntl 
Date: 15th September, 2023.
============================================================================
*/



#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
        int fd[2];
        pipe(fd);
        if(!fork()){
                close(1);
                close(fd[0]);
                fcntl(fd[1],F_DUPFD);
                execlp("ls","ls","-l",NULL);
        }
        else{
                close(0);
                close(fd[1]);
                fcntl(fd[0],F_DUPFD);
                execlp("wc","wc",NULL);
        }
}

