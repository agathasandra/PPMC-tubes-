/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : 5 (Rombongan E)
* Hari dan Tanggal : 15 April 2020
* Asisten (NIM) : Wuri Utami (13217024)
* Nama File : display.c
* Deskripsi : Fungsi untuk menampilkan array ke layar dengan jeda 250ms
*/

#include<stdio.h>
#include<conio.h>
#include<time.h>

void display(char **array_main,int baris,int kolom){
    int ms=250,i,j;
    clock_t start=clock();//menginput waktu sekarang ke variabel start
    while(clock()<start+ms);//loop hingga clock() bertambah sebanyak 250 ms dari variabel start
    system("cls");//fungsi clear screen
    for(i=0;i<baris;i++){//loop untuk mencetak elemen-elemen array ke layar
        for(j=0;j<kolom;j++){
            printf("%c",array_main[i][j]);
        }
        printf("\n");
    }
}
