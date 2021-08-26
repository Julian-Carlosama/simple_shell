#include "holberton.h"

/**
 * Writer - Functions that writw
 *
 * @PtrShell: Reference to struct
 */

void Writer(shell *PtrShell)
{
	write(1, (PtrShell->argvmain)[0],
	len((PtrShell->argvmain)[0]));
	write(1, "No such file or directory\n", 26);
}
