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

extern int skorTotal;       
extern int panjangPapan;    //input tinggi papan dari user
extern int lebarPapan;      //input lebar papan dari user
extern Hadiah daftarHadiah[100]; // Asumsi maksimal 100 hadiah
extern int jumlahHadiah;
extern int xO, yO;


void labelhadiah(char baris[], int x, const Hadiah *h, int lebardalam);
void sortHadiah(Hadiah data[], int jumlah);
void gambarpapan(const Hadiah hadiah[], int jumlahhadiah, int ox, int oy); // Ganti cetakPapan dengan nama asli fungsimu
void cekHadiah(int x, int y);
// Prototipe fungsi dari arsip.c dan animasi.c
void bacaHadiah(Hadiah data[], int *jumlah);
void isiHadiah(Hadiah data[], int *jumlah);
void isiGerak();
void simulasi();
void simpanHadiah(Hadiah data[], int jumlah);
#endif
