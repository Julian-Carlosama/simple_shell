#include "shell.h"

/** 
* MallocPointerArray - Function for allocate a array pointer
* 
* @Number: Number that aloca memmory in the 
*
*
 */
char **MallocPointerArray(size_t Number)
{
    char **ArrayPointer = (char **)malloc(sizeof(char *)*(Number + 1));

    if (ArrayPointer == NULL) 
        return (NULL);
    else
        return (ArrayPointer);
}
/** 
* InitPointerArray - Process each element finished with this character :
*
* @ArrayPointer: Is an array of pointers 
*
* @Path: more
 */
void InitPointerArray(char **ArrayPointer, char *Path)
{
    int Index = 0;

    ArrayPointer[Index++] = strtok(Path, " :\n\t");
    while ((ArrayPointer[Index++] = strtok(NULL, ":\n")));

}

/** 
* FreeShell - Memory Free of the line get 
*
* @Shell: Varible of type shell
*
*/
void FreeShell(shell *Shell, int state)
{
    free(Shell->Line);
    Shell->Line  = NULL;
    Shell->NumberCharacter = 0;

    if (state == 1)
        free(Shell->ArrayPointer);
}


