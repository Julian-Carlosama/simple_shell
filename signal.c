#include "holberton.h"

/**
* signalCtrC - Handle Ctrl + C in in the prompt
*
* @signal: The signal that handle
*
*/

void signalCtrC(int signal)
{
	(void)signal;

	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "$ ", 2);

}
