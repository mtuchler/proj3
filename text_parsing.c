#include "text_parsing.h"

char* lineBuffer[BUFF_SIZE];
char line[BUFF_SIZE];
char c;
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
void closeFile(FILE* f) {
	fclose(f);
	return;
}

//function to parse the target of each line
//inputs buffer to an empty array and pointer to an open file
//returns line number 
int parseTargets(char* name, FILE* file){

	if (file == NULL && name == NULL){
		return 1; 
	}

	else{
		while((c != EOF)){
			fscanf(file, "%s", line);
		       	lineNum++;	
			//for each line in the file
			for(int i = 0; i<lineNum ; i++){
				//read til you encounter a colon character
				if(c == ':' || c == " "){
					//feed the line into the buffer
					lineBuffer[] = line;	
				}
					
				else{
					continue;
				}
			}
		}
	}	
	return 0;
}

//function to parse the dependencies on each line
//inputs buffer to an empty array
//returns an array of strings each one being the name
//of the dependencies
char** parseDependencies(char* name, FILE* file){
	char array[];

	//if name of dependency matches the name of file
	//finds the most recently modified file based on time
	//found in the stat directory
	if(){
		strcpy(line,"/proc/");
        	strcat(line,pid_t);
        	strcat(line,"/stat");
		openFile();

		fscanf(file,"%s ",line);
		closeFile();
	}

	//if dependency is the name of another target
	//commands in specification are ran if the target
	//is out of date and needed to be ran
	if(){
		openFile();
		closeFile();
	}	
	return name;
}

//fucniton parses the command line 
int parseCommandLine(int argc, char **argv, FILE* file){

	if (argc == 0 && argv == NULL && file == NULL){
		return 1;
	}
	else{
		while((c != EOF)){
                        fscanf(file, "%s", line);
                        lineNum++;
                        //for each line in the file
                        for(int i = 0; i<lineNum ; i++){
                                //read til you encounter a tab character
                                if(c == "/t"){
                                        //feed the line into the buffer
                                        lineBuffer[] = line;    
                                }
                                
                                else{
                                        continue;
				}

	}
	return 0;
}
