#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "struktur.h"

//data hadiah
void bacaHadiah(Hadiah data[], int *jumlah) { //pakek pointer supaya bs dikirim balik dan dipakai di file main.c
    FILE *fp = fopen("data/thadiah.txt", "r"); //buka file thadiah di dalem folder data, r mode read doang karena cuman membaca
    if (fp == NULL) {  //kalo ilenya gaada langsung keluar dari fungsi
        *jumlah = 0;
        return;
    }

    char teks[20]; //temp supaya bs milih antara koordinat atau sentienel
    int i = 0; //indeks array dimulai dari 0

    while (fscanf(fp, "%s", teks) != EOF) { //ngambil data string dan disimpan ke teks selama belom ujung file
        if (strcmp(teks, "##") == 0) { //tanda sentinel bandingin apakah isinya ##
            break;
        }

        data[i].x = atoi(teks);
        fscanf(fp, "%d %s %d", &data[i].y, data[i].nama, &data[i].skor);
        i++;
    }

    *jumlah = i; //nilai akhir dari i kedalem *jumlah, jd nnti main.c tau
    fclose(fp); //nutup file
}

void bacaGerak(Gerak data[], int *jumlah) {
    //buka file rute jalan O di folder data dengan mode cuma baca (read)
    FILE *fp = fopen("data/tgerak.txt", "r"); 
    if (fp == NULL) {
        *jumlah = 0;
        return;
    }

    char token[20]; 
    int i = 0;     

    while (fscanf(fp, "%s", token) != EOF) {
        //cek sentinel: kalau nemu "##" di file tgerak.txt, loop langsung berhenti
        if (strcmp(token, "##") == 0) {
            break;
        }

        //kalau bukan "##", ubah teks angka tadi jadi integer koordinat X gerak O
        data[i].x = atoi(token);
        
        //krena file gerak cuma butuh koordinat X dan Y, fscanf berikutnya
        // cuma nyomot 1 angka di sebelahnya buat koordinat Y gerak O
        fscanf(fp, "%d", &data[i].y);
        
        i++; // Naik ke indeks berikutnya buat langkah jalan O selanjutnya
    }

    *jumlah = i; // Kasih tahu main.c total langkah yang bakal dilewati si O
    fclose(fp);  // Tutup file
}

void bacaGerak(Gerak data[], int *jumlah) {
    FILE *fp = fopen("data/tgerak.txt", "r");
    if (fp == NULL) {
        *jumlah = 0;
        return;
    }

    char teks[20];
    int i = 0;

    while (fscanf(fp, "%s", teks) != EOF) {
        if (strcmp(teks, "##") == 0) {
            break;
        }

        data[i].x = atoi(teks);
        fscanf(fp, "%d", &data[i].y);
        i++;
    }

    *jumlah = i;
    fclose(fp);
}
