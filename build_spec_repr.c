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

// dummy text_parsing fxns
//FILE* fileOpen() { return NULL; }
//void fileClose(FILE* f) { fclose(f); return; }
//int parseTargets(char* name) { return 0; }


// function to initialize a new TreeNode
// inputs:	the name of the target file
// 		the line number
// return:	pointer to the new Node
TreeNode* nodeInit(char *name, int line) {
        TreeNode* node = malloc(sizeof(TreeNode));
        // input given name and line number
        node->name = malloc(BUFF_SIZE);
        strcpy(node->name, name);
        node->line = line;
        // for use with DFS
        node->checked = 0;
        // parent and children remain NULL
	// create space for children
	node->children = malloc(sizeof(TreeNode*)*MAX_NODES);

        return node;
}

// function to free a node (may delete)
// inputs:	pointer to Node to be freed
// return:	0 if properly freed
int nodeFree(TreeNode* node) {
        free(node->name);
        node->name = NULL;
	free(node);
	node = NULL;
        return 0;
}

// reads the Makefile and parses targets, turning them to nodes
// passes them into an unsorted array of TreeNodes
// inputs:	idk
// return:	idk
TreeNode** getNodes() {
	// Returned array of TreeNodes
	TreeNode* graph[MAX_NODES];
	// initialize graph to NULL
	for (int i = 0; i < MAX_NODES; i++) {
		graph[i] = NULL;
	}
	// ints and buffer
	int nodeIndex = 0;
	int lineNum = 0;
	char* targetBuff = malloc(BUFF_SIZE);

	// Pointer to the open file
	FILE *f = openFile();
	// Loop thru the file
	while (lineNum >= 0) {
		// parseTargets finds the next line with a viable
		// target and copies it into the input buffer. Then
		// it returns the line number it found it on
		lineNum = parseTargets(targetBuff, f);
		graph[nodeIndex] = nodeInit(targetBuff, lineNum);
		nodeIndex++;
		if (nodeIndex == MAX_NODES) {
			printf("Error: Makefile too long\n");
			exit(1);
		}
	}
	// Close the file
	closeFile(f);

        return graph;
}

// finds a node with a given name in the list
// inputs:      the nodes name and the graph to search
// return:      the TreeNode, or NULL if DNE
TreeNode* find(char* name, TreeNode** graph) {
        int index = 0;
        int cmp;
        // loop until you've hit the max or the end
        // nodes are filled into the graph L to R
        while (index < MAX_NODES && graph[index] != NULL) {
                cmp = strcmp(name, graph[index]->name);
                if (cmp == 0) {
                        return graph[index];
                }
                else {
                        index++;
                }
        }
        // if it leaves the loop without finding a node
        return NULL;

}

// function to add a child to the list
void parentChild(TreeNode* parent, TreeNode* child) {
	// set child's parent node
	child->parent = parent;
	// add child to parent's array
	for (int i = 0; i < MAX_NODES; i++) {
		if (parent->children[i] != NULL) {
			parent->children[i] = child;
			return;
		}
	}
	// no space for more children
	return;
}

void printTree(TreeNode** graph) {
	int i = 0;
	while (i < MAX_NODES && graph[i] != NULL) {
		printf("%i: %s\n", i, graph[i]->name);
		i++;
	}
	return;
}


