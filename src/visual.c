#include "struktur.h" //buat akses ke struktur.h
#include <stdio.h> //buat akses ke fungsi input output

//variabel ekstern dari struktur.h
int panjangPapan = 0;
int lebarPapan   = 0;

//fungsi untuk menghitung jumlah digit dalam sebuah bilangan
int panjangint(int n) {
    int digit = 1;
    if (n < 0) {n = -n; digit++;}
    while (n >= 10) {n /= 10; digit++;}
    return digit;
}

void gambarpapan(const Hadiah hadiah[], int jumlahhadiah, int ox, int oy) {
    int lebardalam = lebarPapan - 2;  //untuk jarak didalam papan
//bingkai atas
    printf("|");
    for (int j = 0; j < lebardalam; j++) {
        printf("--"); }
    printf("|\n");
    //isi papan
    for (int brs = 0; brs < panjangPapan; brs++) {
        char baris[200];
        for (int j = 0; j < lebardalam; j++) {
            baris[j] = ' ';
        }
        //gambar hadiah
        for (int k = 0; k < jumlahhadiah; k++) {
            if (hadiah[k].y == brs &&
                hadiah[k].x >= 0 &&
                hadiah[k].x < lebardalam) {
                labelhadiah(baris, hadiah[k].x, &hadiah[k]);
            }
        }
     //gambar O
        if (oy == brs &&
            ox >= 0 &&
            ox < lebardalam) {
            baris[ox] = 'O';
        }
        printf("|");
        for (int j = 0; j < lebardalam; j++) {
            printf("%c ", baris[j]);
        }
        printf("|\n");
    }
    //bingkai bawah
    printf("|");
    for (int j = 0; j < lebardalam; j++) {
        printf("--");
    }
    printf("|\n"); //akhir bingkai bawah
}

