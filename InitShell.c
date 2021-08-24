#include "shell.h"

/**
* InitShell - Initialize the shell structure
*
* @Shell: Pointer that call shell structure  
*/

void InitShell(shell *Shell)
{
    /* Attributes */
    Shell->NumberCharacter = 0;                      /* Getline */ 
    Shell->Line = NULL;                              /* Getline*/
    Shell->Path = NULL;                              /* Puntero a todas las rutas: /home/bin:/sur/bin/ */
    Shell->FindPath = NULL;                          /* Preguntar por rutas indivudiales */
    Shell->ArrayPointer = NULL;                      /* GetPath */
    Shell->Argv = NULL;                              /* GetPath*/

    /* Metods or functions */
    Shell->GetPath = GetPath;                        /* Find variable Env=PATH, Shell->Path */
    Shell->NumberPath = NumberPath;                  /* Get number elements of the path */
    Shell->MallocPointerArray = MallocPointerArray;  /* Array of pointers for the allocate the path */
    Shell->InitPointerArray = InitPointerArray;      /* Inicialization that allow point to array of pointers */
    Shell->FreeShell = FreeShell;                    /* Free the shell a time executed */
    Shell->Find = Find;                              /* A time find */
    Shell->Execve = Execve;                          /**/
}