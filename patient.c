#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "asem.h"


int main (int argc, char *argv []) {
    
    ainit(argv[0]);
    
    if (argc != 2){
        adebug(0,"usage: patient n\n");
        exit(EXIT_FAILURE);
    }

    char *nom = argv[1];

    if ((strlen(nom) == 0)||(strlen(nom) > 10)){
        adebug(0,"usage: patient n\n");
        exit(EXIT_FAILURE);
    }


    adebug(0,"usage: patient n\n");
    exit(EXIT_FAILURE);

    return 0;
}