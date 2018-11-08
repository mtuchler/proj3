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
	FILE* file  = fopen("Rakefile", "r");

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
				// whitespace handling
				for (int j = 0; j < BUFF_SIZE; j++) {
					if (name[j] == ' ') {
						name[j] = '\0';
						return lineNum++;
					}
				}
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

	for (int n = 0; n < MAX_NODES; n++) {
		dList[n] = malloc(BUFF_SIZE);
	}

	//throw out lines until you get to lineNum
	for(int d = 1; d < lineNum; d++){
		while(fgetc(file) != '\n') {}
	}
	
	// read into line
	for(int e = 0; e < BUFF_SIZE; e++){
		line[e] = fgetc(file);
		if (line[e] == '\n') {
			// append \0 and leave loop
			line[e] = '\0';
			e = BUFF_SIZE;
		}
	}
	// EOF check
	if (feof(file)) {
		return NULL;
	}

	// index of line read from Makefile
	int lineIndex = 0;
	// index of dependant number in dList (first array index)
	int listIndex = 0;
	// index of dependant string in dList (second array index)
	int deppIndex = 0;

	// read until the colon to get the first dependancy
	while (line[lineIndex] != ':') {
		lineIndex++;
	}
	lineIndex++;
	// throw out all subsequent spaces
	while (line[lineIndex] == ' ') {
		lineIndex++;
	}

	// read char by char until you get to a string terminator
	// the remainder of the line is a series of
	// 	- chars making up the dependants
	// 	- followed by some non-zero number of spaces
	// 	- all ending in a terminator
	while (line[lineIndex] != '\0' && listIndex < MAX_NODES) {
		// if you find a non-space, non-terminating char...
		if (line[lineIndex] != ' ') {
			// ...set char in dList and increment
			dList[listIndex][deppIndex] = line[lineIndex];
			deppIndex++;
			// ...look at next char
			lineIndex++;
		}
		// if you find a space char...
		else {
			// append a null terminator
			dList[listIndex][deppIndex] = '\0';
			// ...look at next char and next dependant
			listIndex++;
			deppIndex = 0;
			// while loop ignores multiple consecutive spaces
			while (line[lineIndex] == ' ') {
				lineIndex++;
			}
		}
	}
	// stuff once you've found the \0:
	if (deppIndex != 0) {
		dList[listIndex][deppIndex] = '\0';
		listIndex++;
	}
	dList[listIndex] = NULL;
	
	closeFile(file);

	return dList;
}

//function parses the command line
//reads up to the line if starts with a tab character
//return an array of strings that are passed into execvp() 
//returns NULL on end of cmd lines or EOF
char** parseCommandLine(int* lineNum){
	
	FILE* file = openFile();
	char line[BUFF_SIZE];

        //read each lineNum and throws out the newline
        for(int d = 1; d < *lineNum; d++){
                while(fgetc(file) != '\n') {}
        }

	// check if viable command line
	char c = fgetc(file);
	// quick EOF check
	if (feof(file)) {
		return NULL;
	}
	if (c != '\t') {
		// Ignore a line that starts with a newline or #
		if (c == '\n' || c == '#') {
			(*lineNum)++;
			printf("diving deeper\n");
			return parseCommandLine(lineNum);
		}
		else {
			return NULL;
		}
	}

	// initialize/malloc array and some variables
	char** array = malloc(sizeof(char*)*CMD_SIZE);
	for (int n = 0; n < CMD_SIZE; n++) {
		array[n] = malloc(CMD_SIZE);
	}

	// read in line
	for(int e = 0; e < BUFF_SIZE; e++){
		if (!feof(file) && c != '\n') {
                	line[e] = c;
		}
		else if (feof(file)) {
			return NULL;
		}
		else {
			// you've read to the end of the line
			line[e] = '\0';
			e = BUFF_SIZE;
		}
		c = fgetc(file);
        }

	// index of the line from Makefile
	// starts at 1 because line[0] = '\t'
	int lineIndex = 1;
	// index of the command line argument
	int listIndex = 0;
	// index of next character within command line argument
	int arggIndex = 0;

	// read into the array we return
	while (line[lineIndex] != '\0' && listIndex < MAX_NODES) {
                // if you find a non-space char...
                if (line[lineIndex] != ' ') {
                        // ...set char in array and increment
                        array[listIndex][arggIndex] = line[lineIndex];
                        arggIndex++;
                        // ...look at next char
                        lineIndex++;
                }
                // if you find a space char...
                else {
                        // append a null terminator
                        array[listIndex][arggIndex] = '\0';
                        // ...look at next char and next argument
                        listIndex++;
                        arggIndex = 0;
			lineIndex++;
                }
        }
	// append a null pointer after last arg
	array[listIndex][arggIndex + 1] = '\0';
	array[listIndex + 1] = NULL;

	closeFile(file);
	return array;
}
