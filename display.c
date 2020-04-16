/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*  MODUL 9 – TUGAS BESAR
*  Kelompok         : 5 (Rombongan E)
*  Hari dan Tanggal : Kamis, 16 April 2020
*  Asisten (NIM)    : Wuri Utami (13217024)
*  Nama File        : display.c
*  Deskripsi        : Fungsi untuk menampilkan array ke layar dengan jeda 250ms
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

void display(char **array_main, int baris, int kolom){
    //Deklarasi Variabel
    int ms = 250, i, j;
    clock_t start = clock();
    while(clock() < start + ms); //Kondisi ketika waktu awal lebih kecil daripada waktu awal ditambah jeda
    //Program akan melakukan jeda selama 250ms untuk menjalankan animasi
    system("cls");
    for(i=0; i<baris; i++){
        for(j=0; j<kolom; j++){
            printf("%c", array_main[i][j]); //print array hasil setiap iterasi
        }
        printf("\n");
    }
}
