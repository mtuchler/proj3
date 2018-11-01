#include "text_parsing.h"

//parses the lines of Makefile and blah blah
int parser(int argc, char** argv){
    	FILE* file;
    	int buff = 1024;
	int c;
	char *lineBuffer = (char *)malloc(sizeof(char) * buffer);
	char* token = strok(buff, ":");

	file  = fopen(filename, "r");
	
	if(file == NULL){
		printf("Error opening file\n");
		exit(1);
	}	
	else{
		while(fgets(buff, sizeof(buff), file) != NULL){	
			switch(token):
				case '\t':
				// command line 
					break;
				default:
					//dependencies and targets
					break;
		}	
	}
	fclose(file);

}
