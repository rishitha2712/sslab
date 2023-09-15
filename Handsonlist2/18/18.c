/*
============================================================================
Name : 18.c
Author : Himarishitha Kakunuri
Description : Write a program to find out total number of directories on the pwd.Execute ls -l | grep ^d | wc ?        	             Use only dup2. 
Date: 15th September, 2023.
============================================================================
*/




#include <stdio.h>
#include <unistd.h>

int main(){
        int fd1[2],fd2[2];
        pipe(fd1);
	pipe(fd2);
        if(!fork()){
                close(fd1[0]);
		close(fd2[0]);
		close(fd2[1]);
		dup2(fd1[1],1);
                execlp("ls","ls","-Rl",NULL);
        }
        else{
		if(!fork()){
		       	close(fd1[1]);
			close(fd2[0]);
			dup2(fd1[0],0);
			dup2(fd2[1],1);
               	        execlp("grep","grep","^d",NULL);
		}
	       	else{
			close(fd1[0]);
			close(fd1[1]);
			close(fd2[1]);
                	dup2(fd2[0],0);
                	execlp("wc","wc",NULL);
		}
        }
	return 0;
}
