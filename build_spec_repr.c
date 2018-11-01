/////////////////////////////////////////////////
//
// File:	build_spec_repr.c
// 
// Purpose:	building nodes from text parsing
// 		functions, and returning an array
// 		of TreeNodes
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

#include "build_spec_repr.h"

// function to initialize a new TreeNode
// inputs:	the name of the target file
// 		the line number
// return:	pointer to the new Node
TreeNode nodeInit(char *name, int line) {
        struct TreeNode node;
        // input given name and line number
        node.name = malloc(BUFF_SIZE);
        strcpy(node.name, name);
        node.line = line;
        // for use with DFS
        node.checked = 0;
        // parent and children remain NULL

        return node;
}

// function to free a node (may delete)
// inputs:	pointer to Node to be freed
// return:	0 if properly freed
int nodeFree(TreeNode* node) {
        free(node->name);
        node->name = NULL;
        return 0;
}

// reads the Makefile and parses targets, turning them to nodes
// passes them into an unsorted array of TreeNodes
// inputs:	idk
// return:	idk
TreeNode* getNodes() {
	// Returned array of TreeNodes
	TreeNode graph[MAX_NODES];
	// ints and buffer
	int nodeIndex = 0;
	int lineNum = 0
	char* targetBuff = malloc(BUFF_SIZE);

	// Pointer to the open file
	FILE *f = fileOpen();
	// Loop thru the file
	while (lineNum >= 0) {
		lineNum = parseTargets(targetBuff,f);
		graph[nodeIndex] = nodeInit(targetBuff, lineNum);
		nodeIndex++;
		if (nodeIndex == MAX_NODES) {
			printf("Error: Makefile too long\n");
			exit(1);
		}
	}
	// Close the file
	fileClose(f);

        return graph;
}
