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

int main() {

	char **arg = {NULL};

	printf("before\n");

	execvp("ls", arg);

	printf("after\n");

	return 0;
}
