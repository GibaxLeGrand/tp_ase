#include <stdlib.h>
#include <stdio.h>
#include "asem.h"
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>


// Fichier ouvrir.c à rédiger
int main (int argc, char *argv []) {

    ainit(argv[0]);

    if (argc != 4){
        adebug(0,"usage: ./ouvrir n m t\n");
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int t = atoi(argv[3]);

    if ((n < 1) || (m < 1) || (t < 1)){
        adebug(0,"usage: ./ouvrir n m t\n");
        exit(EXIT_FAILURE);
    }

    

    return 0;
}
