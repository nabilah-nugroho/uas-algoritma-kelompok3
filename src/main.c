#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struktur.h"

//definisi warna buat terminal
#define WARNA_RESET   "\033[0m"
#define WARNA_KUNING  "\033[1;33m"   // warna hadiah normal
#define WARNA_HIJAU   "\033[1;32m"

// Variabel global 
Hadiah daftarHadiah[100];
int jumlahHadiah = 0;
int xO = 0;
int yO = 0;

// Fungsi untuk cek apakah ada di posisi hadiah
void cekDanTandaiHadiah(int x, int y) {
    for (int i = 0; i < jumlahHadiah; i++) {
        if (daftarHadiah[i].x == x && daftarHadiah[i].y == y) {
            printf(WARNA_HIJAU "Hadiah '%s' di (%d,%d) tersentuh! Skor +%d\n" WARNA_RESET,
                   daftarHadiah[i].nama, x, y, daftarHadiah[i].skor);
        }
    }
}

// Fungsi untuk mencetak papan dengan hadiah
void cetakPapanDenganHadiah(int panjang, int lebar) {
    for (int row = 0; row < panjang; row++) {
        for (int col = 0; col < lebar; col++) {
            int adaHadiah = 0;
            for (int i = 0; i < jumlahHadiah; i++) {
                if (daftarHadiah[i].x == col && daftarHadiah[i].y == row) {
                    adaHadiah = 1;
                    if (xO == col && yO == row) {
                        // O sedang di atas hadiah -> warna hijau
                        printf(WARNA_HIJAU "H" WARNA_RESET);
                    } else {
                        // hadiah belum disentuh -> warna kuning
                        printf(WARNA_KUNING "H" WARNA_RESET);
                    }
                    break;
                }
            }
            if (!adaHadiah) {
                if (xO == col && yO == row)
                    printf("O");
                else
                    printf(".");
            }
        }
        printf("\n");
    }
}

void thadiah() {
    char jawab;
    int x, y, skor;
    char nama[20];
    
    bacaHadiah(daftarHadiah, &jumlahHadiah);
    
    sortHadiah(daftarHadiah, jumlahHadiah);
    
    printf("Isi hadiah saat ini:\n");
    printf("|x |y |nama |skor |\n");
    for (int i = 0; i < jumlahHadiah; i++) {
        printf("|%d |%d |%s |%d |\n", 
               daftarHadiah[i].x, 
               daftarHadiah[i].y, 
               daftarHadiah[i].nama, 
               daftarHadiah[i].skor);
    }
    
    printf("ingin mengisi: ");
    scanf(" %c", &jawab);
    
    if (jawab == 'Y' || jawab == 'y') {
        printf("x: "); scanf("%d", &x);
        printf("y: "); scanf("%d", &y);
        printf("nama: "); scanf("%s", nama);
        printf("skor: "); scanf("%d", &skor);
        
        daftarHadiah[jumlahHadiah].x = x;
        daftarHadiah[jumlahHadiah].y = y;
        strcpy(daftarHadiah[jumlahHadiah].nama, nama);
        daftarHadiah[jumlahHadiah].skor = skor;
        jumlahHadiah++;
        
        sortHadiah(daftarHadiah, jumlahHadiah);
        
        simpanHadiah(daftarHadiah, jumlahHadiah);
    }
}

void tgerak() {
    printf("\n--- Menu tambahkan gerakan ---\n");
    isiGerak();
}

void simulasiLiteO() {
    printf("\n--- Simulasi Lite O ---\n");
    
    printf("Masukkan panjang (tinggi) papan: ");
    scanf("%d", &panjangPapan);
    printf("Masukkan lebar papan: ");
    scanf("%d", &lebarPapan);

    bacaHadiah(daftarHadiah, &jumlahHadiah);
    
    simulasi();
}

int main() {
    int pilihan;

    do {
        printf("\n=== Menu Utama ===\n");
        printf("1. Tambahkan Hadiah\n");
        printf("2. Tambahkan Gerakan\n");
        printf("3. Simulasi Lite O\n");
        printf("4. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                thadiah();
                break;
            case 2:
                tgerak();
                break;
            case 3:
                simulasiLiteO();
                break;
            case 4:
                printf("Keluar dari program.\n");
                break;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 4);

    return 0;
}