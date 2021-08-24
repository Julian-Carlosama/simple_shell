/* Imprimir variables de entorno */
/*void printENV(char **env) {

    while(*env != NULL) {
        printf("%s\n", *env);
        env++;
    }
}*/
/*int printENV(char *env) {

    /while(*env != NULL) {
        write(1, *env, 1024);
        write(1, "\n", 1);
         printf("%s\n", env); 
            env++; 
    }/
    ssize_t size;
    int index;
/ imprime todo pero nos da segmentation fall/
    for (index = 0; *env[index]; index++) {
        for (size = 0; env[index][size]; size++)
            ;
        write(STDOUT_FILENO, env[index], size);
        write(STDOUT_FILENO, "\n", 1);
    }
    return(1);

}*/