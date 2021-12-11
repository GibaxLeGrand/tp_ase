#include <stdlib.h>
#include <stdio.h>
#include "asem.h"
#include "shm.h"

// Fichier nettoyer.c à rédiger
int main (int argc, char *argv []) {
    
    ainit(argv[0]);
    
    if (argc > 1){
        adebug(0,"usage: ./nettoyer");
        exit(EXIT_FAILURE);
    }

    shm_unlink("vaccinodrome");
    munmap("vaccinodrome", 8);

    (void) argv ;

    return 0;
}