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
	TreeNode** order = buildOrder(graph);

	pid_t pid;

	int i = 0;
	while (i < MAX_NODES && order[i] != NULL) {
	*/	

	// 1) parse Makefile for commands
	// 2) check if its up to date?
	// 3) loop thru commands, running fork/exec/wait
	
	return;
}

// method used to determine if the file has been updated since
// last compile
// input:	idk yet
// return:	1 if it needs update, 0 if it doesnt
int timeCheck() {
	return 0;
}
