#include <stdlib.h>
#include <stdio.h>
#include "asem.h"

int main (int argc, char *argv []) {
    
    ainit(argv[0]);

    if (argc > 1){
        adebug(0,"usage: ./medecin");
        exit(EXIT_FAILURE);
    }

    (void) argv ;

    adebug(0,"usage: ./medecin");
    exit(EXIT_FAILURE);

    return 0;
}
