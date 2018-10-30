#include "proc_creation_prog_exe.h"

//this method creates a child file from the parent file
//and makes it run as its own once execvp is called 
//thus terminates the process once it is finished
void fork(){
	pid_t  pid;
	pid = fork();
	char buff;
	char imput[256];
	
	//checks if pid is valid or not of the child process
	if (pid < 0){
		printf("Error occured, could not fork\n");
	}
	//if the child process is found, execute it and terminate once finished
	if(pid == 0){
		execvp();	
	}
	//wait for a child process to be found
	else{
		wait();
	}

}


