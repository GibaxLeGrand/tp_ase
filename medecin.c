#include <stdlib.h>
#include <stdio.h>
#include "asem.h"
#include "shm.h"

typedef struct {
    int m;
    asem_t occupe;
    int t;

}box;

int main (int argc, char *argv []) {
    
    ainit(argv[0]);

    if (argc > 1){
        adebug(0,"usage: ./medecin");
        exit(EXIT_FAILURE);
    }



    adebug(0,"usage: ./medecin");
    exit(EXIT_FAILURE);

    return 0;
}
