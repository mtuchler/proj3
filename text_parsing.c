#include "text_parsing.h"

//
FILE* openFile(){
	file  = fopen("Makefile", "r");
	char *lineBuffer = (char *)malloc(sizeof(char) * BUFF_SIZE);
	fclose(file);
}

//function to parse the target of each line
//inputs buffer to an empty array and pointer to an open file
int parseTargets(char* name, FILE* file){

	char* token = strtok(lineBuffer, ":");
	
	if(file == NULL){
		printf("Error opening file\n");
		exit(1);
	}

	else if(feof(file)){
		return -1;
	}

	else{
		while(token!=NULL){
			printf("%s\n", token);
			token = strtok(NULL, "/t");
			//handling target
		
		}
	}	
	return 0:
}

//function to parse the dependencies on each line
//inputs buffer to an empty array
int parseDependencies(char* name, FILE* file){
       
       	char* token = strtok(lineBuffer, "\t");

        if(file == NULL){
                printf("Error opening file\n");
                exit(1);
        }

	else if(feof(file)){
                return -1;
	}

        else{
                while(token!=NULL){
                        printf("%s\n", token);
                        token = strtok(NULL, "");
                        //handling dependencies
                }
        }
	return NULL;
}
