// Fichier shm.c à rédiger
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include "shm.h"
#include "asem.h"

ainit("shm.c");

/**
 * @brief représente le box: chaque box est représenté par un médecin associé à un numéro m.
 * la structure possède aussi le nom du patient qui est présent dans le box afin de pouvoir l'afficher
 * il contient aussi un semaphore occupe permettant de signaler si le box est occupe.
 * 
 * @param m un entier désignant le numéro du box
 * @param nom_patient représentant le nom du patient actuellement dans le box. S'il n'y a pas de patient, le nom sera vide
 * @param occupe semaphore permettant de désigner si le box est actuellement occupé ou non par un patient
 * @param t représente le temps de vaccination
 */

typedef struct {
    int m;
    char *nom_patient;
    asem_t occupe;
    //int arrive;
    int t;
} box_medecin;


/**
 * @brief représente le vaccinodrome: ce dernier contient n sièges et m box. Chaque box contient un médecin attendant un patient
 * Le temps t correspond au temps qu'il faut pour vacciner un patient.
 * 
 * @param fd descripteur du vaccinodrome (?)
 * @param n un entier représentant le nombre de siège dans le vaccinodrome.
 * @param m une liste de plusieurs structures box associés à chaque médecin.
 * @param t un entier représentant le temps d'une vaccination dans le box.
 */

struct vaccinodrome {
    int *fd;
    int *n;
    box_medecin *m;
    int t;
};

/**
 * @brief initialise le vaccinodrome: il déclare une structure vaccinodrome, remplit ses valeurs avec des variables données
 * en argument et leur alloue un espace mémoire en utilisant mmap (peut être utilisé shm_open ?). 
 * A la fin, la fonction doit nous rendre un entier descripteur de fichier afin de pouvoir manipuler les données, -1 sinon.
 * 
 * (arguments pas encore donné, je ne cherche qu'à initialiser l'espace mémoire (test-110)).
 * 
 * @param n donné par ouvrir.c: nombre de siège du vaccinodrome
 * @param m donné par ouvrir.c: nombre de box du vaccinodrome
 * @param t donné par ouvrir.c: temps de vaccination dans un box 
 * 
 */

int init_vaccinodrome(){

    struct vaccinodrome;

    vaccinodrome.n = 0;
    vaccinodrome.box_medecin = sizeof(box_medecin);
    vaccinodrome.t = 0;

    vaccinodrome.fd = mmap(NULL, sizeof(vaccinodrome),PROT_WRITE,MAP_SHARED, -1,0);
    if (vaccinodrome.fd == -1){
        adebug(0,"¨Problem init data\n");
        exit(EXIT_FAILURE);
    }

    printf("vaccinodrome déclaré\n");

    return vaccinodrome.fd;

}

void destroy_vaccinodrome(){
    munmap(NULL, sizeof(vaccinodrome));
}

