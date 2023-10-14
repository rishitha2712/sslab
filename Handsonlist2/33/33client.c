/*
============================================================================
Name : 33client.c
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

void main()
{
    
    struct sockaddr_in servadd;
    char data[100];
    int socketfd = socket(AF_UNIX, SOCK_STREAM, 0);
    
    servadd.sin_addr.s_addr = INADDR_ANY;
    servadd.sin_family = AF_UNIX;
    servadd.sin_port = htons(8081);

    connect(socketfd,(void*)&servadd, sizeof(servadd));
    
    printf("Client to server connection successfully established!\n");

    int rd = read(socketfd, data, 100);
    
    if (rd == -1)
        perror("Error while reading");
    else
        printf("Data from server: %s\n", data);

    int wr = write(socketfd, "Message from the client", 24);
    if (wr == -1)
        perror("Error while writing");
    else
        printf("Data sent to server");

    close(socketfd);
}
