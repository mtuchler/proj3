#include<stdio.h>
#include<string.h> 

int parser(){
    	FILE* fd = NULL;
    	char buff[1024];

	fd = fopen("Makefile","r");
	
	if(fd == NULL){
		printf("Error opening file\n");
		exit(1);
	}	
	else{}

}
