/*
============================================================================
Name : 1.c
Author : Himarishitha Kakunuri
Description : Create the following types of a files using (i) shell command (ii) system call
		a. soft link (symlink system call)
		b. hard link (link system call)
		c. FIFO (mkfifo Library Function or mknod system call)
Date: 29th Aug, 2023.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
	int s=symlink("newfile","newfilesymlink");
	if(s<0){
		perror("Failed to create symbolic link");
		return 1;
	}
	int h=link("newfile","newfilehardlink");
	if(h<0){
		perror("Failed to create hard link");
		return 1;
	}
	int p=mknod("newfifo",S_IFIFO,0);
	if(p<0){
		perror("Failed to create fifo pipe");
	}
	return 0;
}
