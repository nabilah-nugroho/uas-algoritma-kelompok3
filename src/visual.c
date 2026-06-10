#include "struktur.h" //buat akses ke struktur.h
#include <stdio.h> //buat akses ke fungsi input output

//variabel ekstern dari struktur.h
int panjangPapan = 0;
int lebarPapan   = 0;

//fungsi untuk menghitung jumlah digit dalam sebuah bilangan
int panjangint(int n) {
    int digit = 1;
    if (n < 0) {n = -n; digit++;} //untuk skor hadiah dengan tanda minus
    while (n >= 10) {n /= 10; digit++;} //selama angka lebih dari 10 buang digit terakhir dan tambah jumlah digit
    return digit;
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
                labelhadiah(baris, hadiah[k].x, &hadiah[k]); //panggil fungsi labelhadiah untuk menempatkan simbol hadiah pada posisi yang sesuai dalam baris
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
    printf("|"); //cetak bingkai bawah dengan pola yang sama seperti bingkai atas
    for (int j = 0; j < lebardalam; j++) { //cetak "--" sebanyak lebar papan - 2
        printf("--");
    }
    printf("|\n"); //akhir bingkai bawah
}

