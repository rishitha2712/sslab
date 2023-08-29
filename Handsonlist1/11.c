#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
        int fd=open("b.txt",O_RDWR|O_CREAT|O_APPEND);
        int temp=dup(fd);
        int new=dup2(fd,4);
        int dup=fcntl(fd,F_DUPFD,6);
        int wr=write(fd,"Hi How are you\n",15);
        int dwr=write(temp,"I am rishitha\n",14);
        write(fd,"I will be printed in b.txt\n",27);
        write(dup,"Using fcntl\n",12);
        close(fd);
        close(temp);
        close(new);
        close(dup);
        return 0;
}

