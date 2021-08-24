#include "shell.h"

shell sh;
shell *Shell;

void CTRC(int sig) {
    (void)sig;

    if (Shell->Line)
        Shell->FreeShell(Shell, 1);
} 
int main() {

    Shell = &sh;

    /* Inicializamos nuestra estructura de datos (SHELL) --> inicializamos nuestra variable */
    InitShell(Shell);
    /* GetPath: Función que obtiene la ruta de los binarios*/
    Shell->GetPath(Shell);

    /* Manejamos señales */ 
    signal(SIGINT, &CTRC);
    write(1, "$ ", 2);

    /* This is own prompt */
    while(getline(&(Shell->Line), &(Shell->NumberCharacter), stdin) != EOF) {

        /* Procesar los caracteres */
        if (!(Shell->Find(Shell)))
            Shell->Execve(Shell);
        else {
            write(1, "command not found\n", 19);
        }
        /* Finalización procesar caracteres */ 

        /* Memory free */
        Shell->FreeShell(Shell, 0);
        write(1, "$ ", 2); 
    }

    return (0);
}