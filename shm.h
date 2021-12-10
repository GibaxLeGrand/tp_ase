// Fichier shm.h à rédiger

#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <pthread.h>
#include <fcntl.h>

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
 * @param n un entier représentant le nombre de siège dans le vaccinodrome.
 * @param m une liste de plusieurs structures box associés à chaque médecin.
 * @param t un entier représentant le temps d'une vaccination dans le box.
 */

struct vaccinodrome {
    int *n;
    box_medecin *m;
    int t;
};

int init_vaccinodrome();
void destroy_vaccinodrome();




