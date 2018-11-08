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

	char buff[BUFF_SIZE];
	
	int i = parseTargets(buff, f);

	while (i > 0) {
		printf("%i: target = %s\n", i, buff);
		i = parseTargets(buff, f);
	}

	fclose(f);

	printf("end\n");
}
