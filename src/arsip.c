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

void isiHadiah(Hadiah data[], int *jumlah) {
    char pilihan;
    
    printf("\nIsi hadiah saat ini:\n");
    printf("---------------------------\n");
    printf("X\tY\tNama\tSkor\n");
    printf("---------------------------\n");
    for (int i = 0; i < *jumlah; i++) {
        if (data[i].x != -1 && data[i].y != -1) {
            printf("%d\t%d\t%s\t%d\n", data[i].x, data[i].y, data[i].nama, data[i].skor);
        }
    }
    printf("---------------------------\n");

    printf("ingin mengisi: ");
    scanf(" %c", &pilihan);

    if (pilihan == 'Y' || pilihan == 'y') {
        int idx = *jumlah;
        
        printf("x: "); scanf("%d", &data[idx].x);
        printf("y: "); scanf("%d", &data[idx].y);
        printf("nama: "); scanf("%s", data[idx].nama);
        printf("skor: "); scanf("%d", &data[idx].skor);

        if (data[idx].x >= lebarPapan || data[idx].y >= panjangPapan || data[idx].x < 0 || data[idx].y < 0) {
            printf("Error: Koordinat di luar batas papan!\n");
            return;
        }

        (*jumlah)++;
        sortHadiah(data, *jumlah);
        simpanHadiah(data, *jumlah);
        printf("Data berhasil disimpan!\n");
    }
}

void isiGerak() {
    FILE *fp = fopen("data/tgerak.txt", "w");
    if (fp == NULL) {
        printf("Gagal membuka file tgerak.txt\n");
        return;
    }

    int n, x, y;
    printf("Berapa langkah koordinat jalan O yang mau diinput? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Masukkan langkah ke-%d (format: x y): ", i + 1);
        scanf("%d %d", &x, &y);
        
        if (x >= lebarPapan || y >= panjangPapan || x < 0 || y < 0) {
            printf("Peringatan: Koordinat di luar batas papan!\n");
        }
        
        fprintf(fp, "%d %d\n", x, y);
    }

    fprintf(fp, "## ##\n");
    fclose(fp);
    printf("Rute langkah O berhasil disimpan!\n");
}

