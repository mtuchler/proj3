/////////////////////////////////////////////////
//
// File:	prog_creation_proc_exe.c
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


#include "proc_creation_prog_exe.h"

//this method creates a child file from the parent file
//and makes it run as its own once execvp is called 
//thus terminates the process once it is finished
/*
void fork(){
	pid_t  pid;
	pid = fork();
	char buff;
	char imput[256];
	char * arg[];

	//checks if pid is valid or not of the child process
	if (pid < 0){
		printf("Error occured, could not fork\n");
	}
	//if the child process is found, execute it and terminate once finished
	if(pid == 0){
		execvp(arg[0], arg);	
	}
	//wait for a child process to be found
	else{
		wait();
	}

}
*/


