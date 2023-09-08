/*
============================================================================
Name : 8.c
Author : Himarishitha Kakunuri
Description : Write a program to open a file in read only mode,read line by line and display each line as it is read.                Close the file when end of file is reached. 
Date: 29th Aug, 2023.
============================================================================
*/




#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buffer[200];
    int fd=open(argv[1], O_RDONLY);
    int read_bytes;
    char *newline;

    if(fd==-1)
    {
	    printf("Error opening file\n");
    }
    read_bytes=read(fd, buffer, 200);
    if(read_bytes>0)
    {
	    char *start=buffer;
	    while((newline=strchr(start, '\n'))!=NULL)
	    {
		    *newline='\0';
		    write(STDOUT_FILENO, start, strlen(start));
		    write(STDOUT_FILENO, "\n", 1);
		    start=newline+1;      
            }
    } 
    close(fd);
    return 0;
}
