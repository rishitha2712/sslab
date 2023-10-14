/*
============================================================================
Name : 34b.c
Author : Himarishitha Kakunuri
Description :Write a program to create a concurrent server.
	      a. use fork
	      b. use pthread_create
Date: 12th Oct,2023
============================================================================
*/


#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/ip.h>
#include <stdio.h>      
#include <unistd.h>   
#include <pthread.h>

void fun(int *fd)
{
	int nsd=*fd;
        char data[100];	
	char send[20]="I am SERVER:";
        write(nsd, &send, 20);
        read(nsd, &data, 100);
        printf("%s: %lu\n",data,pthread_self());

}

int main()
{
	int sd=socket(AF_UNIX, SOCK_STREAM, 0);
	struct sockaddr_in s,c;
	pthread_t tid;

	s.sin_addr.s_addr = INADDR_ANY;
    	s.sin_family = AF_UNIX;
    	s.sin_port = htons(8000);
	bind(sd, (struct sockaddr*)&s, sizeof(s));

	listen(sd,2);
	printf("Server listening \n" );
	while(1)
	{
		int size=(int)sizeof(c);
		int nsd=accept(sd,(struct sockaddr*)&c,&size);
		printf("Server to client connection successfully established\n");
		pthread_create(&tid, NULL, (void *)fun, &nsd);
	}
	close(sd);
}
