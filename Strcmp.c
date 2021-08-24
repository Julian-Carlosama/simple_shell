#include "shell.h"
/**
* Strcmp - Compare two strings env, PATH= and exit.
* 
* @s1: Take the elements path original PATH 
* 
* @s2: Take the elements of the word path to comparate
*  */
char *Strcmp(char *s1, char *s2)
{
        while(*s2)
        {
                if (*s1 != *s2)
                        return (NULL);
        s1++, s2++;
    }
    return (s1);
}

