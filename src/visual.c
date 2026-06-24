#include "struktur.h" //buat akses ke struktur.h
#include <stdio.h> //buat akses ke fungsi input output

int panjangPapan = 0;
int lebarPapan   = 0;

int panjangint(int n) {
    int digit = 1;
    if (n < 0) {n = -n; digit++;} //untuk skor hadiah dengan tanda minus
    while (n >= 10) {n /= 10; digit++;} //selama angka lebih dari 10 buang digit terakhir dan tambah jumlah digit
    return digit;
}

void labelhadiah(char baris[], int x, const Hadiah *h, int lebardalam) {
    char teks[100];
    //gabungkan nama dan skor jadi satu string
    sprintf(teks, "%s%d", h->nama, h->skor);

    int i = 0;
    // Tulis nama hadiah ke dalam baris dengan aman
    while (h->nama[i] != '\0' && (x + i) < lebardalam) {
        baris[x + i] = h->nama[i];
        i++;
    }
}

void gambarpapan(const Hadiah hadiah[], int jumlahhadiah, int ox, int oy) {
    int lebardalam = lebarPapan - 2;  //untuk jarak didalam papan
//bingkai atas
    printf("|");
    for (int j = 0; j < lebardalam; j++) { //cetak "--" sebanyak lebar papan - 2
        printf("--"); }
    printf("|\n"); //akhir bingkai atas
    //isi papan
    for (int brs = 0; brs < panjangPapan; brs++) { //looping untuk setiap baris papan
        char baris[200];
        for (int j = 0; j < lebardalam; j++) { //inisialisasi setiap posisi dalam baris dengan spasi
            baris[j] = ' ';
        }
        //gambar hadiah
        for (int k = 0; k < jumlahhadiah; k++) { //looping untuk setiap hadiah yang ada
            if (hadiah[k].y == brs && //cek apakah hadiah berada di baris yang sedang digambar
                hadiah[k].x >= 0 && //cek apakah posisi x hadiah valid (tidak negatif)
                hadiah[k].x < lebardalam) { //cek apakah posisi x hadiah valid (tidak melebihi lebar papan)
                labelhadiah(baris, hadiah[k].x, &hadiah[k], lebardalam);
                }
        }

     //gambar O
        if (oy == brs && //cek apakah posisi y O sama dengan baris yang sedang digambar
            ox >= 0 && //cek apakah posisi x O valid (tidak negatif)
            ox < lebardalam) { //cek apakah posisi x O valid (tidak melebihi lebar papan)
            baris[ox] = 'O'; //tempatkan simbol 'O' pada posisi yang sesuai dalam baris untuk menggambarkan O
        }
        printf("|");
        for (int j = 0; j < lebardalam; j++) { //cetak setiap karakter dalam baris yang sudah diisi dengan hadiah dan O
            printf("%c ", baris[j]); //cetak karakter diikuti spasi untuk jarak antar karakter
        }
        printf("|\n"); //akhir baris papan
    }
    //bingkai bawah
    printf("|"); 
    for (int j = 0; j < lebardalam; j++) { 
        printf("--");
    }
    printf("|\n"); 
}