#include "text_parsing.h"

//parses the lines of Makefile and blah blah
int parser(int argc, char** argv){
    	FILE* file;
    	int buff = 1024;
	int c;
	char *lineBuffer = (char *)malloc(sizeof(char) * buffer);
	char* token = strok(buff, ":");

	file  = fopen("Makefile","r");
	
	if(file == NULL){
		printf("Error opening file\n");
		exit(1);
	}	
	else{
		while(){	
			if(){
								
			}
		}	
	}
	fclose(file);

}
