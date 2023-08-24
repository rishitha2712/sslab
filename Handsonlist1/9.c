#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <time.h>

int main(int argc, char *argv[])
{
  struct stat s;
  if (argc != 2) {
    printf("Error: Enter File Name");
    exit(EXIT_FAILURE);
  }
  if (stat(argv[1], &s) == -1) {
    perror("stat");
    exit(EXIT_FAILURE);
  }
  printf("I-node number:%lu\n",s.st_ino);
  printf("Hard Links count:%lu\n",s.st_nlink);
  printf("UID:%u\n",s.st_uid);
  printf("GID:%u\n",s.st_gid);
  printf("File size:%ld bytes\n",s.st_size);
  printf("Block size:%ld bytes\n",s.st_blksize);
  printf("No.of Blocks:%ld\n",s.st_blocks);
  printf("Last file access:%s",ctime(&s.st_atime));
  printf("Last file modification:%s",ctime(&s.st_mtime));
  printf("Last status change:%s",ctime(&s.st_ctime));
  return 0;
}

