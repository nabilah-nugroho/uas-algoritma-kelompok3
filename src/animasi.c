#include "struktur.h"
#include <time.h>

void wait(float x) {
    time_t start;
    time_t current;
    time(&start);
    do
        time(&current);
    while (difftime(current,start) < x);
}

void simulasiGerak() {
    FILE *f;
    gerak G;

    f = fopen("tgerak.txt", "r");

    if (f != NULL) {
        while (fscanf(f, "%d %d", &G.x, &G.y) != EOF) {

            system("cls");

            // update posisi O
            posisiO.x = G.x;
            posisiO.y = G.y;

            // tampilkan papan
            tampilPapan();

            wait(1);
        }

        fclose(f);
    }
}
