/////////////////////////////////////////////////
//
// File:	prog_creation_proc_exe.h
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

#ifndef PROG_CREATION_PROC_EXE_H
#define PROG_CREATION_PROC_EXE_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "build_spec_graph.h"

struct stat{ 
               dev_t     st_dev;     /* ID of device containing file */ 
               ino_t     st_ino;     /* inode number */ 
               mode_t    st_mode;    /* protection */ 
               nlink_t   st_nlink;   /* number of hard links */ 
               uid_t     st_uid;     /* user ID of owner */ 
               gid_t     st_gid;     /* group ID of owner */ 
               dev_t     st_rdev;    /* device ID (if special file) */ 
               off_t     st_size;    /* total size, in bytes */ 
               blksize_t st_blksize; /* blocksize for file system I/O */ 
               blkcnt_t  st_blocks;  /* number of 512B blocks allocated */ 
               time_t    st_atime;   /* time of last access */ 
               time_t    st_mtime;   /* time of last modification */ 
               time_t    st_ctime;   /* time of last status change */ 
          };

#endif
