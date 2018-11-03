/////////////////////////////////////////////////
//
// File:	build_spec_graph.c
//
// Author:	Abhi Kosuri
// 		Mike Tuchler
// All files:	build_spec_graph.c, .h
// 		build_spec_repr.c, .h
// 		proc_creation_prog_exe.c, .h
// 		text_parsing.c, .h
// 		main.c, README
//
/////////////////////////////////////////////////

#include "build_spec_graph.h"

// parses Makefile for dependencies, and sets parents/children
// TODO does this do it for one node or all of them?
int connectNodes(TreeNode** graph) {
	TreeNode* currNode = graph[0];
	TreeNode* nodeCheck;
	int numNodes = 0;
	// List of strings parsed as dependencies
	char** dList;
	
	FILE* f = openFile();

	// find the number of nodes
	while(currNode != NULL && numNodes < MAX_NODES) {
		currNode = graph[numNodes];
		numNodes++;
	}

	// loop through nodes to get dependencies
	// if successful, graph[i] is parent of graph[k]
	for (int i = 0; i < numNodes; i++) {
		currNode = graph[i];
		dList = parseDependencies(currNode->line, f);
		// loop through dependencies to see if they are nodes
		int j = 0;
		while (dList[j] != NULL) {
			// search for a node with that name
			nodeCheck = find(dList[j],graph);
			// if a node is found...
			if (nodeCheck != NULL) {
				// add dependencies
				parentChild(graph[i], nodeCheck);
			}
			// DO WE CHECK IF ITS A VIABLE FILE????
			j++;
		}
	}

	closeFile(f);

	return 0;
}

// using a DFS, creates a build order for the Makefile
// also checks for cycles, which are bad
int buildOrder() {
	return 0;
}

