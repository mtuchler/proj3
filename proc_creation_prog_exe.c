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

// this method loops through each node in the build order
// and calls execNode on it if applicable
//
// you only execute a node if it's a target (i.e. has commands)
// AND, if its a file, if it's out of date.
void execLoop(TreeNode** order) {
	int execute = 0;

	int i = 0;
	while (order[i] != NULL) {
		// check if it's a target
		// if it has a line number in the makefile, yes
		if (order[i]->line > 0) {
			execute = 1;
		}
		// check if it's a file
		if (access(order[i]->name, F_OK) == 0) {
			// if so, check if it's out of date
			if (timeCheck(order[i])) {
				execute = 1;
			}
		}

		// great! you're good to go!
		if (execute) {
			printf("execute %s\n", order[i]->name);
			execNode(order[i]);
		}
		i++;
	}
	return;
}


//this method creates a child process from the parent process
//and makes it run as its own once execvp is called 
//thus terminates the process once it is finished
void execNode(TreeNode* node) {

	int* line = &(node->line);
	char** cmdList;
	pid_t pid;
	int status;
	 
	cmdList = parseCommandLine(line);
	while(cmdList != NULL){
		pid = fork();

		if(pid < 0){
			printf("Process could not be forked\n");
			exit(1);
		}
               	else if(pid == 0){
			execvp(cmdList[0], cmdList);
		}
		else{
			wait(&status);
		}	
		//done executing one line
		(*line)++;
		cmdList = parseCommandLine(line);
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
// last compile. Assume input is a proper file that exists
// input:	idk yet
// return:	1 if it needs update, 0 if it doesnt
int timeCheck(TreeNode* node) {
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
	// no need to compile
	return 0;
}
