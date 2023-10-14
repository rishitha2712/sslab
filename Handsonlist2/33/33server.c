/*
============================================================================
Name : 33server.c
Author : Himarishitha Kakunuri
Description : Write a program to communicate between two machines using socket.
Date: 12th October, 2023.
============================================================================
*/


#include <sys/types.h>  
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdio.h>      
#include <unistd.h>     

int main()
{
    
    struct sockaddr_in servadd,cliadd;
    char data[100];
    int socketfd = socket(AF_UNIX, SOCK_STREAM, 0);
    
    servadd.sin_addr.s_addr = INADDR_ANY;
    servadd.sin_family = AF_UNIX;
    servadd.sin_port = htons(8081);

    bind(socketfd, (void*) (&servadd), sizeof(servadd));
    listen(socketfd, 5);
    int size = sizeof(cliadd);

    int newsfd = accept(socketfd, (void*) (&cliadd), &size);
    int wr = write(newsfd, "I'm the server", 15);
    if (wr == -1)
        perror("Error while writing");
    else
        printf("Data sent to client\n");

    int rd = read(newsfd, data, 100);
    if (rd == -1)
            perror("Error while reading");
    else
        printf("Data from client: %s\n", data);
    
    close(socketfd);
    close(newsfd);
    
    return 0;
}
