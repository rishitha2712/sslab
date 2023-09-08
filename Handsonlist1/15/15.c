/*
============================================================================
Name : 15.c
Author : Himarishitha Kakunuri
Description : Write a program to display the environmental variable of the user (use environ).
Date: 29th Aug, 2023.
============================================================================
*/



#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

extern char **environ;

int prefixmatch(const char *pre,const char *str){
	return strncmp(pre,str,strlen(pre))==0;
}

int main(){
	char **env=environ;
	while(*env!=NULL){
		if(prefixmatch("USER",*env))
			printf("%s\n",*env);
		env++;
	}
	return 0;
}
