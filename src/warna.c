#include <stdio.h>

// Koleksi warna ANSI Escape
#define ANSI_RESET   "\x1b[0m"
#define ANSI_RED     "\x1b[31m"
#define ANSI_GREEN   "\x1b[32m"
#define ANSI_YELLOW  "\x1b[33m"
#define ANSI_BLUE    "\x1b[34m"
#define ANSI_MAGENTA "\x1b[35m"
#define ANSI_CYAN    "\x1b[36m"

void cetakBerwarna(char karakter, int status) {
    // Jika status 0, cetak normal (bukan hadiah)
    if (status == 0) {
        printf("%c ", karakter);
    } 
    // Jika status > 0, berarti ini hadiah! Kita bedakan warna berdasarkan angka statusnya
    else {
        switch (status % 6) {
            case 1: printf(ANSI_RED "%c " ANSI_RESET, karakter); break;
            case 2: printf(ANSI_GREEN "%c " ANSI_RESET, karakter); break;
            case 3: printf(ANSI_YELLOW "%c " ANSI_RESET, karakter); break;
            case 4: printf(ANSI_BLUE "%c " ANSI_RESET, karakter); break;
            case 5: printf(ANSI_MAGENTA "%c " ANSI_RESET, karakter); break;
            case 0: printf(ANSI_CYAN "%c " ANSI_RESET, karakter); break;
        }
    }
}