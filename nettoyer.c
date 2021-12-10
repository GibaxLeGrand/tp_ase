#include <stdlib.h>
#include <stdio.h>
#include "asem.h"

// Fichier nettoyer.c à rédiger
int main (int argc, char *argv []) {
    
    ainit(argv[0]);
    
    if (argc > 1){
        adebug(0,"usage: ./nettoyer");
        exit(EXIT_FAILURE);
    }

    (void) argv ;

    return 0;
}