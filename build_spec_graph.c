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
TreeNode* node_init(char *name, int line) {
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

int main() {
	return 0;
}
