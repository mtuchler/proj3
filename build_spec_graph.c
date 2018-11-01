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

// function to initialize a new TreeNode
TreeNode* nodeInit(char *name, int line) {
	struct TreeNode node;
	// input given name and line number
	node.name = malloc(BUFF_SIZE);
	strcpy(node.name, name);
	node.line = line;
	// for use with DFS
	node.checked = 0;
	// parent and children remain NULL

	return &node;
}

// function to free a node (may delete)
int nodeFree(TreeNode* node) {
	free(node->name);
	node->name = NULL;
	return 0;
}

// reads the Makefile and parses targets, turning them to nodes
// passes them into an unsorted array of TreeNodes
int getNodes() {
	return 0;
}

// parses Makefile for dependencies, and sets parents/children
// TODO does this do it for one node or all of them?
int connectNodes() {
	return 0;
}

// using a DFS, creates a build order for the Makefile
// also checks for cycles, which are bad
int buildOrder() {
	return 0;
}

int main() {
	return 0;
}
