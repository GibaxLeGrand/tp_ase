#include <stdlib.h>
#include <stdio.h>
#include "asem.h"
#include "shm.h"

// Fichier fermer.c à rédiger
int main (int argc, char *argv []) {
    
    ainit(argv[0]);

    if (argc > 1){
        adebug(0,"usage: ./fermer ");
        exit(EXIT_FAILURE);
    }

    int fd = destroy_vaccinodrome();

    if (fd == -1){
        adebug(0,"Nothing to close");
        exit(EXIT_FAILURE);
    }

    shm_unlink("vaccinodrome");
    return 0;
}
