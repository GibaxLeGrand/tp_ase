#include <stdlib.h>
#include <stdio.h>
#include "asem.h"

// Fichier fermer.c à rédiger
int main (int argc, char *argv []) {
    
    ainit(argv[0]);

    if (argc < 3){
        perror("usage: ./fermer n");
        exit(EXIT_FAILURE);
    }

    (void) argv ;

    return 0;
}
