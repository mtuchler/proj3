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
// TODO does this do it for one node or all of them?
int connectNodes() {
	return 0;
}

// using a DFS, creates a build order for the Makefile
// also checks for cycles, which are bad
int buildOrder() {
	return 0;
}
