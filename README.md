<p align="center">
  <img src="assets/image.png" alt="yey" width="850"/>
</p>

## Project Management

Progress pengerjaan:
[![Project Board](https://img.shields.io/badge/Project-Board-blue?logo=github)](https://github.com/nabilah-nugroho/uas-algoritma-kelompok3/projects/1)
Tracking terdapat assignee per file dan status revisi masing-masing PIC fitur 

## Struktur Proyek dan PIC

- `src/`
  - `main.c` — Abi
  - `arsip.c` — Nabilah
  - `animasi.c` — Arkaan
  - `skor.c` — Kimi
  - `sorting.c` — Diyar
  - `visual.c` — Nindira
  - `struktur.h` — Nabilah
- `data/` — berisi file `thadiah.txt` dan `tgerak.txt` untuk input/output game

## Cara Build

Gunakan compiler C seperti `gcc`.

```powershell
git clone https://github.com/nabilah-nugroho/uas-algoritma-kelompok3.git
```

```powershell
cd uas-algoritma-kelompok3
```

```powershell
code .
```

```powershell
gcc src/animasi.c src/arsip.c src/main.c src/skor.c src/sorting.c src/struktur.h src/visual.c -o LiteO
```

```powershell
./LiteO
```
