#include "struktur.h"
#include <stdio.h>
//testestes
int skorTotal; 

extern Hadiah daftarHadiah[]; 
extern int jumlahHadiah;

void cekHadiah(int x, int y) {
    for (int i = 0; i < jumlahHadiah; i++) {
        if (daftarHadiah[i].x == x && daftarHadiah[i].y == y) {

            skorTotal += daftarHadiah[i].skor;

            daftarHadiah[i].x = -1;
            daftarHadiah[i].y = -1;

            hapusHadiahDimakan();
        }
    }
}

void infoSkor(){
    printf("\nSkor sekarang: %d\n", skorTotal);
}

void hapusHadiahDimakan() {
    FILE *fp = fopen("data/thadiah.txt", "w");
    if (fp == NULL) {
        printf("Gagal membuka thadiah.txt\n");
        return;
    }

    for (int i = 0; i < jumlahHadiah; i++) {
        if (daftarHadiah[i].x != -1 && daftarHadiah[i].y != -1) {
            fprintf(fp, "%d %d %s %d\n", daftarHadiah[i].x, daftarHadiah[i].y, daftarHadiah[i].nama, daftarHadiah[i].skor);
        }
    }

    fprintf(fp, "## ## ## ##\n");
    fclose(fp);
}