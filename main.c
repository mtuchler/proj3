/////////////////////////////////////////////////
//
// File:	main.c
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

#include <stdio.h>
#include <unistd.h>
#include "build_spec_repr.h"

int main() {
	printf("main\n");

	TreeNode* graph[MAX_NODES];

	for (int i = 0; i < MAX_NODES; i++) {
		graph[i] = NULL;
	}

	graph[0] = nodeInit("red",1);
	graph[1] = nodeInit("yellow",2);
	graph[2] = nodeInit("blue",3);

	printTree(graph);

	return 0;
}
