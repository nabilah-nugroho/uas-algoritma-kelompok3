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

        }
    }
}