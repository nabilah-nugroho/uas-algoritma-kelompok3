// struktur.h
#ifndef STRUKTUR_H
#define STRUKTUR_H

// struct data hadiah
typedef struct {
    int x;
    int y;
    char nama[20];
    int skor;
} Hadiah;

// struct gerakan o
typedef struct {
    int x;
    int y;
} Gerak;

extern int skorTotal;       //menampung skor si O selama simulasi
extern int panjangPapan;    //input tinggi papan dari user
extern int lebarPapan;      //input lebar papan dari user
extern int xO;
extern int yO;

int lebihBesar(Hadiah a, Hadiah b)

void sortHadiah(Hadiah data[], int jumlah)

#endif