/*
============================================================================
Name : 21b.c
Author : Himarishitha Kakunuri
Description : Write two programs so that both can communicate by FIFO -Use two way communications. 
Date: 15th September, 2023.
============================================================================
*/




#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
        char buf1[20],buf2[20];
        
	int fd1=open("fifo1",O_WRONLY);
        if(fd1<0){
                perror("Error in opening pipe");
        }
        printf("Enter text: ");
        scanf("%[^\n]",buf1);
        write(fd1,buf1,sizeof(buf1));
 	
	int fd2=open("fifo2",O_RDONLY);
        if(fd2<0){
                perror("Failed to open pipe");
        }
        read(fd2,buf2,sizeof(buf2));
        printf("Text from pipe: %s\n",buf2);
	
	return 0;
}
