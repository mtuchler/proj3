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

	/*// create a graph and put it in build-order
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
	int line = node->line;
	char** cmdList;
	pid_t pid;
	int status;
	
	//not a target 
	if(line == -1){
		return;
	}
	 
	else{
		cmdList = parseCommandLine(node->line);
		while(cmdList != NULL){
			pid = fork();

			if(pid < 0){
                        	printf("Process could not be forked\n");
                       		exit(1);
                	}

                	else if(pid == 0){
                        	pid = getpid();
                        	execvp(cmdList[0], cmdList);
                	}
			else{
				wait(&status);
			}	
		}
		
	}
	return;
}

static time_t getFileModifiedTime(const char *path)
{
    struct stat attr;
    if (stat(path, &attr) == 0)
    {
        return attr.st_mtime;
    }
    return 0;
}

// method used to determine if the file has been updated since
// last compile
// input:	idk yet
// return:	1 if it needs update, 0 if it doesnt
int timeCheck(TreeNode* node){
	// file check - if its a node but not a file, run its commands
	if (access(node->name, F_OK) != 0) {
		return 1;
	}

	time_t t_node = getFileModifiedTime(node->name);
	time_t t_child;

	// loop thru children
	for (int i = 0; i < node->numchild; i++) {
		//do thing
		t_child = getFileModifiedTime(node->children[i]->name);
		// if child was modified MORE SECONDS after the parent,
		// then parent needs to be recompiled.
		if( difftime(t_node, t_child) <= 0 ) {
			return 1;
		}
	}

	return 0;
}
