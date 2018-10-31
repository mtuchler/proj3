#include "text_parsing.h"

//parses the lines of Makefile and blah blah
int parser(int argc, char** argv){
    	FILE* F;
    	char buff[1024];
	int c;
	
	F  = fopen("Makefile","r");
	
	if(F == NULL){
		printf("Error opening file\n");
		exit(1);
	}	
	else{
		while((c =fgetc(input_file)) != EOF){	
			if(){
								
			}
		}	
	}
	fclose(fd);

}
