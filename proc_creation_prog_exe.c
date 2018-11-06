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
void execNode(TreeNode* node){
	/* THIS IS SOME MAIN METHOD BUSINESS
	 *
	// create a graph and put it in build-order
	TreeNode** graph = getNodes();
	connectNodes(graph);
	TreeNode** order = buildOrder(graph);
	
	//components used for forking processes
	pid_t parent = getpid();
	pid_t pid;
	int status;
	
	//used to store the arguments from the command line
	char* argv[MAX_ARGS];	

	while (i < MAX_NODES && order[i] != NULL) {
		
		//creating and checking processes forked 
		pid = fork();
		if(pid < 0){
			printf("Process could not be forked\n");
			exit(1);
		}

		else if(pid == 0){
			pid = getpid();
			execvp(argv[0], argv);
			exit(0);
		}

		else{ 
			wait(pid, &status);
		}
	
		

	*/	
	// 1) parse Makefile for commands
	// 2) check if its up to date?
	// 3) loop thru commands, running fork/exec/wait
	
	return 0;
}

// method used to determine if the file has been updated since
// last compile
// input:	idk yet
// return:	1 if it needs update, 0 if it doesnt
int timeCheck(){

	//components for running fstat to find the time
        //of modification on files
        int i = 0;
        struct stat st;

	//call to fstat is made
        if(fstat(i, &st) < 0){ 
                return 1;
        }

        //use st_mtime to find the last modification time

	return 0;
}
