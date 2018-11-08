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
	dList = parseDependencies(5);

	//print dList
	for (int i = 0; i < MAX_NODES; i++) {
		if (dList[i] == NULL) {
			break;
		}
		printf("%s\n", dList[i]);
	}

	fclose(f);
	printf("end\n");
}
