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

	printf("\n");
	printTree(graph);
	printf("\n");
	printTree(order);

}

void testParseCommandLine() {
	char** dList;
        int lineNum[1];
        lineNum[0] = 2;

        dList = parseCommandLine(lineNum);

        if (dList == NULL) {
                printf("null array\n");
        }
        else {
                //print dList
                for (int i = 0; i < CMD_SIZE; i++) {
                        if (dList[i] == NULL) {
                                break;
                        }
                        printf("%s\n", dList[i]);
                }
        }
}

void testGetNodes() {

	TreeNode** graph = getNodes();
	connectNodes(graph);
	printTree(graph);

	return;
}
