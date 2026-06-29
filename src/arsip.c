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
        //cek sentinel kalau nemu "##" di file tgerak.txt, loop langsung berhenti
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

void simpanHadiah(Hadiah data[], int jumlah) {
    FILE *fp = fopen("data/thadiah.txt", "w");
    if (fp == NULL) {
        printf("gabisa membuka thadiah.txt\n");
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        if (data[i].x != -1 && data[i].y != -1) {
            fprintf(fp, "%d %d %s %d\n", data[i].x, data[i].y, data[i].nama, data[i].skor);
        }
    }

    fprintf(fp, "## ## ## ##\n");
    fclose(fp);
}

void isiGerak() {
    FILE *fp = fopen("data/tgerak.txt", "r+");

    if (fp == NULL) {
        fp = fopen("data/tgerak.txt", "w");
        if (fp == NULL) {
            printf("Gagal membuka file tgerak.txt\n");
            return;
        }
    } else {
        char token[20];
        long posisiSentinel = -1;

        while (1) {
            long posisi = ftell(fp);

            if (fscanf(fp, "%s", token) == EOF) {
                break;
            }

            if (strcmp(token, "##") == 0) {
                posisiSentinel = posisi;
                break;
            }
        }

        if (posisiSentinel != -1) {
            fseek(fp, posisiSentinel, SEEK_SET);
        } else {
            fseek(fp, 0, SEEK_END);
        }
    }

    int n, x, y;
    printf("Berapa langkah koordinat jalan O yang mau ditambahkan? ");
    scanf("%d", &n);

    fprintf(fp, "\n");

    for (int i = 0; i < n; i++) {
        printf("Masukkan langkah ke-%d (format: x y): ", i + 1);
        scanf("%d %d", &x, &y);
        fprintf(fp, "%d %d\n", x, y);
    }

    fprintf(fp, "## ##\n");

    fclose(fp);
    printf("Rute langkah O berhasil ditambahkan!\n");
}