#include "shell.h"

/**
 * Execve  - Function that excecute the command.
 *
 * @PtrShell: Pointer to the struct of data
 *
 * Return: Child process
 */
int Execve(shell *PtrShell)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == 0)
	{
		int state = 0;

		state = execve(*(PtrShell->argv), PtrShell->argv, NULL);

		if (state == -1)
		{
			write(1, "Command not found\n", 18);
			free(PtrShell->lineptr);
			free(PtrShell->AllPaths);
			free(PtrShell->argv);
			exit(0);
		}
	}
	else
	{
		wait(&status);
	}
	return (child_pid);
}


/**
 * Execve2  - Function that excecute the command.
 *
 * @PtrShell: Pointer to the struct of data
 *
 * Return: Child process
 */
int Execve2(shell *PtrShell)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == 0)
	{
		execve(PtrShell->BuildPath, PtrShell->argv, NULL);
	}
	else
	{
		wait(&status);
	}
	return (child_pid);
}
