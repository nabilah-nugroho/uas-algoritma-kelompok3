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

void simulasi() {
    FILE *f;
    Gerak g;

    f = fopen("tgerak.txt", "r");

    if (f == NULL) {
        printf("File tgerak.txt tidak ditemukan!\n");
        return;
    }

    while (fscanf(f, "%d %d", &g.x, &g.y) != EOF) {

        // posisi O sekarang ada di g.x dan g.y

        printf("Posisi O : (%d,%d)\n", g.x, g.y);

        wait(1);
    }

    fclose(f);
}

while (fscanf(f, "%d %d", &g.x, &g.y) != EOF) {

    system("cls");      // No. 3

    // update posisi O
    xO = g.x;
    yO = g.y;

    // cek apakah ada hadiah yang dimakan
    cekHadiah(xO, yO);

    // cetak papan terbaru
    cetakPapan();

    wait(1);            // No. 1
}