#include "struktur.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
extern Hadiah daftarHadiah[];
extern int jumlahHadiah; 

// Fungsi wait tidak berubah 
void wait(float x) {
    time_t start;
    time_t current;
    time(&start);
    do
        time(&current);
    while (difftime(current,start) < x);
}

void simulasi() {
    FILE *f = fopen("data/tgerak.txt", "r"); 
    if (f == NULL) {
        perror("Gagal membuka file data/tgerak.txt");
        return;
    }
    
    Gerak g;
    while (fscanf(f, "%d %d", &g.x, &g.y) == 2) {
        
        xO = g.x;
        yO = g.y;

        cekHadiah(xO, yO);

        system("cls");
        cekHadiah(xO, yO);   //tukerrrr
        gambarpapan(daftarHadiah, jumlahHadiah, xO, yO);
        infoSkor();
        wait(1); 
    }

    fclose(f);
}