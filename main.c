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
#include "build_spec_repr.h"

int main() {
	printf("start\n");
	FILE* f = fopen("Makefile", "r");

	char** dList;
	int lineNum[1];
	lineNum[0] = 9;

	dList = parseCommandLine(lineNum);

	printf("wth?\n");

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

	fclose(f);
	printf("end\n");
}
