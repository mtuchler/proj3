#include "text_parsing.h"

char* lineBuffer[BUFF_SIZE];
char line[BUFF_SIZE];
int lineNum;
//
FILE* openFile(){
	file  = fopen("filename", "r");
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
int parseTargets(char* name, FILE* file){

	if(feof(file)){
		return -1;
	}

	else{
		while(fgets(line, sizeof line, file)!=NULL){
			if(lineBuffer[i] != ":"){
				for(int i = 0; i<strlen; i++){
					lineBuffer[i] = line;
					lineNum++;
					name = lineBuffer[0];	
				}
			}
			//handling target
			//first element of array is the target
		}
	}	
	return lineNum;
}

//function to parse the dependencies on each line
//inputs buffer to an empty array
//returns an array of strings each one being the name
//of the dependencies
int parseDependencies(int lineNum, FILE* file){
       
	char* array[];

	if(feof(file)){
                return -1;
	}

        else{
		while(fgets(line, sizeof line, file)!="\n"){
        		for(int j = 1; j<sizeOf(lineBuffer); j++){
				//dependencies start after the comma
				//put dependencies into a seperate array
				array[j];
			}
                        //handling dependencies
                }
        }
	return NULL;
}

//fucniton parses the command line 
int parseCommandLine(int argc, char **argv, FILE* file){

	if(feof(file)){
                return -1;
        }
	
	else{
		while(fgets(line, sizeof line, file) == \t){
			if(){
				
			}
		}
	}
	return NULL;
}
