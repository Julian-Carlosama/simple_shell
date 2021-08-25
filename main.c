#include "holberton.h"

/**
 * main - Function main
 *
 * @argc: Argument to
 * @argv: Array of
 * @env: Environment variable
 *
 * Return: retunr 0
 */
/* Shell */
int main(int argc, char **argv, char **env)
{

	shell VShell;
	(void) argc;
	VShell.argvmain = argv;

	InitShell(&VShell, env);              /* inicializamos la estructura */

	if (!(VShell.Terminal)())                 /* Modo no interactivo*/
		NoInteractivo(&VShell);
	else
	{                                     /* Modo interactivo */
		(VShell.Interactivo)(&VShell);
	}
	free(VShell.argv);
	return (0);
}
