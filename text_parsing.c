#include "text_parsing.h"

char* lineBuffer[BUFF_SIZE];
char line[BUFF_SIZE];
int lineNum;
//
FILE* openFile(){
	FILE* file  = fopen("filename", "r");

	if(file == NULL){
                printf("Error opening file\n");
                exit(1);
	}

	return file;
}

void closeFile(FILE* f) {
	fclose(f);
	return;
}

//function to parse the target of each line
//inputs buffer to an empty array and pointer to an open file
//returns line number 
int parseTargets(char* name, FILE* file){

	// dummy text for fewer errors
	if (file == NULL && name == NULL) { return 1; }	
/*
	int strlen = strlen(name);

	if(feof(file)){
		return -1;
	}

	else{
		while(fgets(line, sizeof line, file)!=NULL){
			if(lineBuffer[i] != ':'){
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
*/
	return 0;
}

//function to parse the dependencies on each line
//inputs buffer to an empty array
//returns an array of strings each one being the name
//of the dependencies
char** parseDependencies(int lineNum, FILE* file){

// dummy line plz delete
if (lineNum == 0 && file == NULL) { printf("\n"); }
 /*	
	char** array;

	if(feof(file)){
                return NULL;
	}
        else{
		if(*lineBuffer[0] == '\n') {
        		for(int j = 1; j < BUFF_SIZE; j++){
				//dependencies start after the comma
				//put dependencies into a seperate array
				array[j];
			}
		}
		else if(*lineBuffer[0] == '\t') {
		
		}
                        //handling dependencies
        }
	return array;
*/ return NULL;
}

//fucniton parses the command line 
int parseCommandLine(int argc, char **argv, FILE* file){

	if (argc == 0 && argv == NULL && file == NULL) { return 1; }
/*
	if(feof(file)){
                return -1;
        }
	
	else{
		while(fgets(line, sizeof line, file) == '\t'){
			if(1){
				
			}
		}
	}

*/
	return 0;
}
