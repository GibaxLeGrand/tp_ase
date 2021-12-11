// Fichier shm.c à rédiger
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <errno.h>
#include "shm.h"
#include "asem.h"

struct vaccinodrome{
    int n;
    int m;
    int t;
}vacc;

int init_vaccinodrome(int n, int m, int t){

    int fd = 0;
    fd = shm_open("vaccinodrome", O_CREAT | O_EXCL, 0777);
    
    vacc.n = n;
    vacc.m = m;
    vacc.t = t;

    write(fd,"kekw" , 8);

    if (fd == -1){
        adebug(0,"Problem init vaccinodrome\n");
        exit(EXIT_FAILURE);
    }

    mmap("vaccinodrome", 8, PROT_WRITE,MAP_SHARED, fd, 0);

    return fd;
}

int destroy_vaccinodrome(){
    munmap("vaccinodrome", 8);
    int fd = is_vaccinodrome_open();
    if (fd == -1){ 
        fd = shm_unlink("vaccinodrome");
        if (fd == -1){
            return -1;
        }
    }
    
    return 0;
}


int is_vaccinodrome_open()
{
    return shm_open("vaccinodrome", O_EXCL, 0777);
}


