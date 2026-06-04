#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <struktur.h>

void warna (int warna) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), warna);
}

void thadiah() {
    warna(11); //warna biru muda
    printf("\n--- Menu tambahkan hadiah ---\n");
    // logika untuk menambahkan thadiah
    warna(7); //balik lagi ke warna default(putih)
}

void tgerak() {
    warna(14); //warna kuning
    print("\n--- Menu tambahkan gerakan ---\n");
    // logika untuk menambahkan tgerak
    warna(7)//balik lagi ke warna default(putih)
}

void simulasiLiteO() {
    warna(10); // warna hijau
    printf("\n--- Simulasi Lite O ---\n");
    //logika buat animasi Lite O
    warna(7); //balik lagi ke warna default(putih)
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
                tGerak();
                break;
            case 3:
                simulasiLiteO();
                break;
            case 4:
                printf("Keluar dari program.\n");
                system("exit");
                exit(0); //buat matiin program setelah keluar
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 4);

    return 0;
}