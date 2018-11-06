/////////////////////////////////////////////////
//
// File:        text_parsing.c
//
// Author:      Abhi Kosuri
//              Mike Tuchler
// All files:   build_spec_graph.c, .h
//              build_spec_repr.c, .h
//              proc_creation_prog_exe.c, .h
//              text_parsing.c, .h
//              main.c, README
//
/////////////////////////////////////////////////


#include "text_parsing.h"

char line[BUFF_SIZE];
int lineNum;

//opens the file and error handles
FILE* openFile(){
	FILE* file  = fopen("filename", "r");

	if(file == NULL){
                printf("Error opening file\n");
                exit(1);
	}

	return file;
}

//method to close the file once it has been openend
void closeFile(FILE* file) {
        fclose(file);
        return;
}

//function to parse the target of each line
//inputs buffer to an empty array and pointer to an open file
//returns line number 
int parseTargets(char* name, FILE* file){
	
	char* token;
	char delim = ':';

	while(!feof(file)){
		fscanf(file, "%s", line);

		//read til you encounter a colon character
		if(line[0] != '\n' && line[0] != '\t'){	
			token = strtok(line, &delim);
		}

		if (token == NULL){
			printf("%d: incorrect target", lineNum);
			exit(1);								}

		else{
			strcpy(name,token);
			return lineNum;
		}
	}		
	return 0;
}

//function to handle the dependencies as they could be the
//name of another target or name of another file 
//takes reads each line in from the line buffer checking for
//dependencies.
char** parseDependencies(int lineNum){
	
	FILE* file = openFile();

	char** dList = malloc(sizeof(char*)*MAX_NODES);
	char c = fgetc(file);
	char* token1;

	for (int n = 0; n < MAX_NODES; n++) {
		dList[n] = malloc(BUFF_SIZE);
	}

	//read each lineNum and find the dependencies
	for(int d = 1; d < lineNum; d++){
		while(c != '\n') {
			c = fgetc(file);
		}
	}
	
	// read into line
	for(int e = 0; e < BUFF_SIZE; e++){
		line[e] = fgetc(file);
	}

	int index = 0;
	int delim = ' ';
	strtok(line, &delim);
	token1 = strtok(line, &delim);
	while(token1 != NULL && index < MAX_NODES){
		strcpy(dList[index],token1);
		index++;
		token1 = strtok(line, &delim);
	}
	
	closeFile(file);

	return dList;
}

//function parses the command line
//reads up to the line if starts with a tab character
//return an array of strings that are passed into execvp() 
int parseCommandLine(int lineNum){
	
	FILE* file = openFile();

	// initialize/malloc array and some variables	
	char** array = malloc(sizeof(char*)*CMD_SIZE);
	for (int n = 0; n < CMD_SIZE; n++) {
                array[n] = malloc(CMD_SIZE);
        }
	char c = fgetc(file);
	char* token2;


        //read each lineNum and throws out the newline
        for(int d = 1; d < lineNum; d++){
                while(c != '\n') {
                        c = fgetc(file);
                }
        }

	// check if viable command line
	c = fgetc(file);
	if (c != '\t') {
		return NULL;
	}

	// read in line
	for(int e = 0; e < BUFF_SIZE; e++){
		if (!feof(file) && c != '\n') {
                	line[e] = c;
		}
		else if (feof(file) && c != '\n') {
			return NULL;
		}
		else {
			// you've read to the end of the line
			e = BUFF_SIZE;
		}
		c = fgetc(file);
        }

	int index = 0;
        strtok(line, '\t');
        token2 = strtok(line, ' ');
        while(token2 != NULL && index < CMD_SIZE){
                strcpy(array[index],token2);
                index++;
                token2 = strtok(line, ' ');
        }

	closeFile(file);
	return array;
}
