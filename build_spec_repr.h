/////////////////////////////////////////////////
//
// File:	build_spec_repr.h
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

#ifndef BUILD_SPEC_REPR_H
#define BUILD_SPEC_REPR_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "text_parsing.h"

// Declaring and Defining the TreeNode struct
typedef struct TreeNode TreeNode;
struct TreeNode {
        char *name;
        int line;
        TreeNode *parent;
        TreeNode **children;
        int checked;
};

// Constants
static const int MAX_NODES = 64;

// Declaring functions
TreeNode* nodeInit(char* name, int line);
int nodeFree(TreeNode* node);
TreeNode** getNodes();

#endif
