/*
============================================================================
Name : 27b.c
Author : Himarishitha Kakunuri
Description : Write a program to execute ls -Rl by the following system call.
              b. execlp 
Date: 8th September, 2023.
============================================================================
*/




#include <unistd.h>
#include <stdio.h>  
#include <stdlib.h> 

int main(void) {
  execlp("/bin/ls", "ls", "-Rl", NULL);
  perror("Return from execlp() not expected");
  exit(EXIT_FAILURE);
}
