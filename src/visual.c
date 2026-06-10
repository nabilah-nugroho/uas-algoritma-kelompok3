#include "struktur.h" //buat akses ke struktur.h
#include <stdio.h> //buat akses ke fungsi input output

//variabel ekstern dari struktur.h
int skorTotal    = 0;
int panjangPapan = 0;
int lebarPapan   = 0;

void gambarpapan(const Hadiah hadiah[], int jumlahhadiah, int ox, int oy) {
    int lebardalam = lebarPapan - 2;  //untuk jarak didalam papan
//bingkai atas
    printf("|");
    for (int j = 0; j < lebardalam; j++) printf("-");
    printf("|\n");

    for (int brs = 0; brs < panjangPapan; brs++) {

        char baris[200];
        for (int j = 0; j < lebardalam; j++) baris[j] = ' ';

        for (int k = 0; k < jumlahhadiah; k++) {
            if (hadiah[k].y == brs) {
                labelhadiah(baris, hadiah[k].x, &hadiah[k]);
            }
        }

        if (oy == brs && ox >= 0 && ox < lebardalam) {
            baris[ox] = 'O';
        }

        printf("|");
        for (int j = 0; j < lebardalam; j++) printf("%c", baris[j]);
        printf("|\n");
    }

    printf("|");
    for (int j = 0; j < lebardalam; j++) printf("-");
    printf("|\n");

    printf("Skor O: %d\n", skorTotal);
}

