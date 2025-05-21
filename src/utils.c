// This file contains a utility functions for error messaging and exiting.

#include "pipex.h"

// FILE
void	perror_and_exit(char *msg, int *pipe_ends);

//	+++++++++++++++
//	++ FUNCTIONS ++
//	+++++++++++++++

// Displays an error message using perror(), closes the pipe (if provided),
// and exits with failure status.
void	perror_and_exit(char *msg, int *pipe_ends)
{
	perror(msg);
	if (pipe_ends)
	{
		if (close(pipe_ends[0]) == -1)
			perror("Error closing pipe end [0]");
		if (close(pipe_ends[1]) == -1)
			perror("Error closing pipe end [1]");
	}
	exit(EXIT_FAILURE);
}
