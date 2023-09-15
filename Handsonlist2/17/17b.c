/*
============================================================================
Name : 17b.c
Author : Himarishitha Kakunuri
Description : Write a program to execute ls -l | wc.
	      b. use dup2 
Date: 15th September, 2023.
============================================================================
*/



#include <stdio.h>
#include <unistd.h>

int main(){
        int fd[2];
        pipe(fd);
        if(!fork()){
                close(1);
                close(fd[0]);
                dup2(fd[1],1);;
                execlp("ls","ls","-l",NULL);
        }
        else{
                close(0);
                close(fd[1]);
                dup2(fd[0],0);
                execlp("wc","wc",NULL);
        }
	return 0;
}

