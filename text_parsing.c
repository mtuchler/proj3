#include "text_parsing.h"

char lineBuffer[BUFF_SIZE];
int line = 0;
//
FILE* openFile(){
	file  = fopen("Makefile", "r");
	int c = getc(file);

	if(file == NULL){
                printf("Error opening file\n");
                exit(1);
        }

	fclose(file);
}

//function to parse the target of each line
//inputs buffer to an empty array and pointer to an open file
//returns line number 
int  parseTargets(char* name, FILE* file){

	int strLen = strlen(file);

	if(feof(file)){
		return -1;
	}

	else{
		while(scanf("%d" , &c) != EOF){
			for(int i = 0; i<strlen; i++){
				
			}
			//handling target
		
		}
	}	
	return line;
}

//function to parse the dependencies on each line
//inputs buffer to an empty array
//returns an array of strings each one being the name
//of the dependencies
int parseDependencies(int line, FILE* file){
       
	char* array[];

	if(feof(file)){
                return -1;
	}

        else{
                while(token!=NULL){
			for(int i = 0; i<sizeOf(Array);i++){
				
			
			}
                        printf("%s\n", token);
                        token = strtok(NULL, ":");
                        //handling dependencies
                }
        }
	return NULL;
}
