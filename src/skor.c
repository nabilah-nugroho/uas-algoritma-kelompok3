#include <stdio.h>
#include "struktur.h"

int skorTotal = 0; 
int panjangPapan = 0;
int lebarPapan = 0;

void cekTabrakan(Gerak posisiOSekarang, Hadiah daftarHadiah[], int jumlahHadiah) {
    
    // Cek semua hadiah satu per satu
    for (int i = 0; i < jumlahHadiah; i++) {
        
        // Cek jika koordinat sama DAN hadiahnya masih ada
        if (posisiOSekarang.x == daftarHadiah[i].x && posisiOSekarang.y == daftarHadiah[i].y && daftarHadiah[i].skor > 0) {
            
            // Tambah skor total dengan skor hadiah
            skorTotal = skorTotal + daftarHadiah[i].skor;
            
            // Set skor jadi 0 agar hadiah hilang dari layar
            daftarHadiah[i].skor = 0;
            
            // Berhenti cek karena hadiah sudah dimakan
            break;
        }
    }
}