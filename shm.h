// Fichier shm.h à rédiger

#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include <pthread.h>
#include <fcntl.h>

int init_vaccinodrome(int n, int m, int t);
int destroy_vaccinodrome();
int is_vaccinodrome_open();





