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
#include "build_spec_graph.h"
#include "proc_creation_prog_exe.h"

void testParseCommandLine();
void testGetNodes();

int main(int argc, const char* argv[]) {
	TreeNode** graph = getNodes();
	TreeNode* root = getRoot(argc, argv, graph);
	connectNodes(graph);
	TreeNode** order = buildOrder(root, graph);

/*	printf("\n");
	printTree(graph);
	printf("\n"); 
	printTree(order);
*/
	execLoop(order);

}
