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
int connectNodes(TreeNode** graph) {
	TreeNode* currNode = graph[0];
	TreeNode* nodeCheck;
	int numNodes = 0;
	// List of strings parsed as dependencies
	char** dList;

	// find the number of nodes
	while(graph[numNodes] != NULL && numNodes < MAX_NODES) {
		numNodes++;
	}

	// allows us to add new nodes to the graph
	int nextNodeIndex = numNodes;

	// loop through nodes to get dependencies
	// if successful, graph[i] is parent of graph[k]
	for (int i = 0; i < numNodes; i++) {
		if (graph[i] == NULL) {
			printf("%i = numNodes\n", numNodes);
			return 0;
		}
		currNode = graph[i];
		printf("----TARGET: %s----\n", currNode->name);
		dList = parseDependencies(currNode->line);
		// Null handling for dList
		if (dList == NULL) {
			return 0;
		}

		// loop through dependencies to see if they are nodes
		int j = 0;
		while (dList[j] != NULL) {
			// search for a node with that name
			nodeCheck = find(dList[j],graph);
			printf("%s searched\n", dList[j]);
			// if a node is found...
			if (nodeCheck != NULL) {
				printf("\tsearch success\n");
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
					if (nextNodeIndex < MAX_NODES) {
						graph[nextNodeIndex] = nodeInit(dList[j], -1);
						parentChild(graph[i], graph[nextNodeIndex]);
						nextNodeIndex++;
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
