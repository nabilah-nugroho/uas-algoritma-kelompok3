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

