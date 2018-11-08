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

int lineNum = 0;

//opens the file and error handles
FILE* openFile() {
	FILE* file  = fopen("makefile", "r");

	if(file == NULL) {
		file = fopen("Makefile", "r");
		if (file == NULL) {
                	printf("Error opening file\n");
                	exit(1);
		}
	}

	return file;
}

//method to close the file once it has been openend
void closeFile(FILE* file) {
	lineNum = 0;
        fclose(file);
        return;
}

//function to parse the target of each line
//inputs buffer to an empty array and pointer to an open file
//returns line number 
int parseTargets(char* name, FILE* file){
	
	char* token;
	char line[BUFF_SIZE];
	char delim = ':';
	// only initialize lineNum if you're first to do it
	if (lineNum == 0) {
		lineNum = 1;
	}

	while(!feof(file)){
		char c;
		// read in line
		for (int i = 0; i < BUFF_SIZE; i++) {
			c = fgetc(file);
			if (c != '\n') {
				line[i] = c;
			}
			else {
				// append end-of-line char and leave loop
				line[i] = '\0';
				i = BUFF_SIZE;
			}
		}
		// second EOF check -- jank
		if (feof(file)) {
			return 0;
		}

		// ignore lines that start with \n, \t, or #
		//read til you encounter a colon character
		if (line[0] != '\0' && line[0] != '\t' && line[0] != '#') {	
			token = strtok(line, &delim);
			if (token == NULL){
				printf("%d: incorrect target\n", lineNum);
				exit(1);
			}
			else{
				strcpy(name,token);
				return lineNum++;
			}
		}
		else {
			//line starts with a \n or \t or #: ignore it
		}
		lineNum++;
	}		
	return 0;
}

//function to handle the dependencies as they could be the
//name of another target or name of another file 
//takes reads each line in from the line buffer checking for
//dependencies.
char** parseDependencies(int lineNum){
	
	FILE* file = openFile();
	char line[BUFF_SIZE];

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
	char delim = ' ';
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
//returns NULL on end of cmd lines or EOF
char** parseCommandLine(int lineNum){
	
	FILE* file = openFile();
	char line[BUFF_SIZE];

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
		// TODO Accept a line that starts with a newline
		if (c == '\n') {
			array[0] = "";
			return array;
		}
		else {
			return NULL;
		}
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
	char delim = ' ';
        strtok(line, "\t");
        token2 = strtok(line, &delim);
        while(token2 != NULL && index < CMD_SIZE){
                strcpy(array[index],token2);
                index++;
                token2 = strtok(line, &delim);
        }

	closeFile(file);
	return array;
}
