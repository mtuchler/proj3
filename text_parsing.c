#include "text_parsing.h"

//parses the lines of Makefile and blah blah
int parser(int argc, char** argv){
    	FILE* file;
    	int buff = 1024;
	int c;
	char *lineBuffer = (char *)malloc(sizeof(char) * buffer);
	char* token = strtok(buff, ":");

	file  = fopen(filename, "r");
	
	if(file == NULL){
		printf("Error opening file\n");
		exit(1);
	}	
	else{
		while(token!=NULL){
			printf("%s\n", token);
			token = strtok(NULL, ":");
			//handling target and dependencies
		}	

	}
	fclose(file);

}
