#include "holberton.h"

/**
 * BuildPath - Build the path to the current executable
 *
 * @PtrShell: Pointer to the struct of data
 *
 * Return: Process suscessfull
 */
int BuildPath(shell *PtrShell)
{
	struct stat sb;
	int Index = 0;
	int len1 = 0;
	int len2 = 0;
	char *lineptr = NULL;

	while ((PtrShell->AllPaths)[Index] != NULL)
	{
		len1 = len((PtrShell->AllPaths)[Index]);
		len2 = len((PtrShell->argv)[0]);

		lineptr = (char *)malloc(sizeof(char) * (len1 + len2 + 2));

		if (lineptr != NULL)
		{
			CopyPath(lineptr, (PtrShell->AllPaths)[Index], (PtrShell->argv)[0]);

			if (stat(lineptr, &sb) == 0)
			{
				PtrShell->BuildPath = lineptr;
				return (0);
			}
			Index++;
			free(lineptr);
		} else
			return (1);
	}
	return (1);
}

/**
 * Interactivo - Interactive mode
 *
 * @PtrShell: Pointer to the struct of data
 *
 * Return: void
 */
/* Modo interactivo */
void Interactivo(shell *PtrShell)
{
	struct stat sb;

	PtrShell->GetPATH(PtrShell);
	while (write(1, "$ ", 2) &&
	((getline(&(PtrShell->lineptr), &(PtrShell->n), stdin)) != EOF))
	{ signal(SIGINT, signalCtrC);
		if ((LineIsSapce(PtrShell->lineptr) == 1) || *(PtrShell->lineptr) == '\n')
			continue;
		if (StrCmp(PtrShell->lineptr, "exit") == 0)
		{ /* Antes de salir Liberar memoria */
			free(PtrShell->lineptr);
			free(PtrShell->AllPaths);
			exit(0);
		} else if (StrCmp(PtrShell->lineptr, "env") == 0)
			printENV(PtrShell->env);
		BuildArgs(PtrShell); /* Obtenemos he inicialzamos el array de lineprt */
		if ((PtrShell->argv)[0][0] == '/')
		{
			if (stat((PtrShell->argv)[0], &sb) == -1)
				write(1, "Command not found\n", 18);
			else
			{ Execve(PtrShell);
				free(PtrShell->BuildPath);
				PtrShell->BuildPath = NULL;
			}
		} else
		{
			/* ls ---> /bin/ls */
			if (BuildPath(PtrShell) == 0)
			{ Execve2(PtrShell);
				free(PtrShell->BuildPath);
			} else
				write(1, "Command not found\n", 18);
		}
		if (PtrShell->argv != NULL)
		{ free(PtrShell->argv);
			PtrShell->argv = NULL;
		}
	} free(PtrShell->lineptr);
	free(PtrShell->AllPaths);
}

/**
 * NoInteractivo - Interactive mode
 *
 * @PtrShell: Pointer to the struct of data
 *
 * Return: void
 */
/* Modo interactivo */
void NoInteractivo(shell *PtrShell)
{
	struct stat sb;

	PtrShell->GetPATH(PtrShell);
	if (((getline(&(PtrShell->lineptr), &(PtrShell->n), stdin)) != EOF))
	{
		if (StrCmp(PtrShell->lineptr, "exit") == 0)
		{ /* Antes de salir Liberar memoria */
			freeAll(PtrShell);
			exit(0);
		} else if (StrCmp(PtrShell->lineptr, "env") == 0)
			printENV(PtrShell->env);
		BuildArgs(PtrShell); /* Obtenemos he inicialzamos el array de lineprt */
		if ((PtrShell->argv)[0][0] == '/')
		{
			if (stat((PtrShell->argv)[0], &sb) == -1)
			{
				write(1, (PtrShell->argvmain)[0],
					  len((PtrShell->argvmain)[0]));
				write(1, "No such file or directory \n", 27);
			}
			else
			{ Execve(PtrShell);
				free(PtrShell->BuildPath);
				PtrShell->BuildPath = NULL;
			}
		} else
		{/* ls ---> /bin/ls */
			if (BuildPath(PtrShell) == 0)
			{ Execve2(PtrShell);
				free(PtrShell->BuildPath);
			} else
				write(1, "No such file or directory \n", 27);
		}
		if (PtrShell->argv != NULL)
		{ free(PtrShell->argv);
			PtrShell->argv = NULL;
		}
	} free(PtrShell->lineptr);
	free(PtrShell->AllPaths);
}

/**
 * Terminal - Functions that define a terminal
 *
 * Return: Process suscessfull
 */
/* Modo interactivo */
/* Para verificar si estamos en una terminal o no */
int Terminal(void)
{
	if (!isatty(STDIN_FILENO))
		return (0);
	else
		return (1);
}

/**
 * InitShell- Init the data structure.
 *
 * @PtrShell: Pointer to the struct of data
 * @env: pointer to the environment variable
 * Return: void
 */
/* Modo interactivo */
/* Inicialozamos la estructura de datos*/
void InitShell(shell *PtrShell, char **env)
{
	PtrShell->env = env;
	PtrShell->lineptr = NULL;
	PtrShell->n = 0;
	PtrShell->PATH = NULL;
	PtrShell->NumberPaths = 0;
	PtrShell->AllPaths = NULL;
	PtrShell->argv = NULL;
	PtrShell->BuildPath = NULL;

	PtrShell->Terminal = Terminal;
	PtrShell->Interactivo = Interactivo;
	PtrShell->GetPATH = GetPATH;
		PtrShell->NoInteractivo = NoInteractivo;

}
