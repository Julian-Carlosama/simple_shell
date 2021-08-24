#include "shell.h"

/**
* CopyPath - Copy the argument/command and paste to the path
*
* @dest: Pointer that contains the path
*
* @src1: Pointer that contains the argument
*
* @src2: Pointer that contains the argument
*/
void CopyPath(char *dest, char *src1, char *src2)
{
	int state = 1;

	while (*src1 || *src2)
	{
		if (*src1)
			*dest++ = *src1++;
		else if (!*src1 && state)
		{
			*dest++ = '/';
			state = 0;
		}
		else if (*src2 != '\n')
			*dest++ = *src2++;
		else if (*src2 == '\n')
			src2++;
	}
	*dest = '\0';
}
