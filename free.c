#include "holberton.h"

/**
* freeAll - Free all variables allocated
*
* @PtrShell: Reference our structure
*
* Return: No return
*/
void freeAll(shell *PtrShell)
{
	free(PtrShell->lineptr);
	free(PtrShell->argvmain);
	free(PtrShell->AllPaths);
}
