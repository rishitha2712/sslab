#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char* argv[]){
	struct stat s;
        if (argc != 2) {
    		printf("Error: Enter File Name");
    		exit(EXIT_FAILURE);
  	}
	if (stat(argv[1], &s) == -1) {
    		perror("stat");
  	        exit(EXIT_FAILURE);
  	}
	printf("File type: ");

           switch (s.st_mode & S_IFMT) {
           case S_IFBLK:  printf("Block device\n");            break;
           case S_IFCHR:  printf("Character device\n");        break;
           case S_IFDIR:  printf("Directory\n");               break;
           case S_IFIFO:  printf("FIFO Pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("Regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
	   }
	return 0;
}
