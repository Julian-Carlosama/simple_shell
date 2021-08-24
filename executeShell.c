#include "shell.h"
/**
 * Execve - Function that create a process child Creates and 
 * waits for the parent, when the previously verified command 
 * is executed, it will be released.
 *
 * @Shell: Call the structure
 *
 * Return: The pid of the child.
 */

int Execve(shell *Shell)
{
	pid_t child_pid = 0;
	int status = 0;
	child_pid = fork();

	if (child_pid == 0)
		execve(*(Shell->Argv), Shell->Argv, NULL);
	else
		wait(&status);

	free(Shell->FindPath); /* Pendiente eliminar */
	free(Shell->Argv); /* Pendiente eliminar */
	return (child_pid);
}
