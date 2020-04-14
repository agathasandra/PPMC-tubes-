/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : 5 (Rombongan E)
* Hari dan Tanggal :
* Asisten (NIM) : Wuri Utami (13217024)
* Nama File : game-of-life.c
* Deskripsi : Program utama yang mensimulasikan game of life
*/

#include<stdio.h>

int main(){
    int;
    char;

    printf("---------------------------------------- SELAMAT DATANG DI PERMAINAN GAME OF LIFE ----------------------------------------\n\n");
    printf("Pada permainan ini, kita akan melakukan simulasi mengenai kondisi hidup dan mati pada sel.\n");
    printf("Pada sel akan ada 2 buah karakter.\n");
    printf("Karakter '-' menandakan kondisi sel yang mati dan karakter 'X' menandakan kondisi sel yang hidup.\n");
    printf("Permainan ini ditentukan oleh kondisi awal permainan, yaitu berdasarkan posisi sel pada setiap seed.\n\n");
    printf("Adapun beberapa peraturan yang berlaku pada permainan ini, yaitu: \n");
    printf("1. Jika sel memiliki kurang dari 1 tetangga yang hidup, maka sel tersebut akan mati/ underpopulation.\n");
    printf("2. Jika sel memiliki 2 tetangga yang hidup, maka sel tersebut akan tetap hidup pada iterasi selanjutnya /next generation.\n");
    printf("3. Jika sel memiliki 3 tetangga yang hidup, maka sel menjadi hidup pada iterasi selanjutnya /reproduction.\n");
    printf("4. Jika sel memiliki 4 tetangga yang hidup, maka sel tersebut akan mati pada iterasi selanjutnya /overpopulation.\n\n");
    printf("Mari kita mulai permainannya!\n");
    
    
    return 0;
}
