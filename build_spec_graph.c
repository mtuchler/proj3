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

	// find the number of nodes
	while(currNode != NULL && numNodes < MAX_NODES) {
		currNode = graph[numNodes];
		numNodes++;
	}

	// loop through nodes to get dependencies
	// if successful, graph[i] is parent of graph[k]
	for (int i = 0; i < numNodes; i++) {
		currNode = graph[i];
		dList = parseDependencies(currNode->line);
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
			// otherwise, it's a dependency but not a target
			// if it's a file, create a node for it
			else {
				//filecheck
				//access returns 0 when it succeeds
				if (access(dList[j], F_OK) != 0) {
					//create node
					if (numNodes < MAX_NODES) {
						numNodes++;
						graph[numNodes] = nodeInit(dList[j], -1);
						parentChild(graph[i], graph[numNodes]);
					}
					else {
						printf("Error: Too many nodes.\n");
					}
				}
			}
			j++;
		}
	}

	return 0;
}

// using a DFS, creates a build order for the Makefile
// also checks for cycles, which are bad
// input:	the graph, i.e. list of node*s
// return:	list of node*s in build/execution order
TreeNode** buildOrder(TreeNode** graph) {
	// 1) determine the root node (from cmdline)
	char* cmdline = NULL;//TODO parseRoot();
	TreeNode* root = find(cmdline, graph);
	// handle NULL input
	if (root == NULL) {
		printf("Invalid make argument: %s\n", cmdline);
		exit(1);
	}
	// 2) initialize new buildOrder array
	TreeNode** order = malloc(sizeof(TreeNode*)*MAX_NODES);
	for (int i = 0; i < MAX_NODES; i++) {
		order[i] = NULL;
	}
	// 3) call DFS on root node
	DFS(root, order);

	return order;
}
