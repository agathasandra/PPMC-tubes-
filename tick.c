/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*  MODUL 9 – TUGAS BESAR
*  Kelompok         : 5 (Rombongan E)
*  Hari dan Tanggal : Kamis, 16 April 2020
*  Asisten (NIM)    : Wuri Utami (13217024)
*  Nama File        : tick.c
*  Deskripsi        : Fungsi untuk mencetak array setelah lewat 1 iterasi
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

void tick(char **array_main, int m, int n){
    //Deklarasi Variabel
    int i, j, k, atas, bawah, kanan, kiri;
    int kounter = 0;
    int indeks = 0;
    char temp2[8];
    char *temp=(char *)malloc(m*n*sizeof(char));
    //Cek kondisi tetangga dari sel
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if (i == 0){
                atas = (m-1);
                bawah = i+1;
            }
            else if (i == (m-1)){
                atas = i-1;
                bawah = 0;
            }
            else{
                atas = i-1;
                bawah = i+1;
            }
            if (j == 0){
                kiri = (n-1);
                kanan = j+1;
            }
            else if (j == (n-1)){
                kiri = j-1;
                kanan = 0;
            }
            else{
                kiri = j-1;
                kanan = j+1;
            }
            //Kondisi tetangga sel
            temp2[0] = array_main[atas][kiri];
            temp2[1] = array_main[atas][j];
            temp2[2] = array_main[atas][kanan];
            temp2[3] = array_main[i][kiri];
            temp2[4] = array_main[i][kanan];
            temp2[5] = array_main[bawah][kiri];
            temp2[6] = array_main[bawah][j];
            temp2[7] = array_main[bawah][kanan];
            for (k=0; k<8; k++){
                if (temp2[k] == 'X'){
                    kounter = kounter+1;
                }
            }
            //Cetak kondisi sel (hidup/mati) sesuai dengan aturan permainan
            if (array_main[i][j] == 'X'){
                if (kounter == 2 || kounter == 3){
                    temp[indeks] = 'X';
                }
                else{
                    temp[indeks] = '-';
                }
                indeks = indeks+1;
            }
            else if (array_main[i][j] == '-'){
                if (kounter == 3){
                    temp[indeks] = 'X';
                }
                else{
                    temp[indeks] = '-';
                }
                indeks = indeks+1;
            }
            kounter = 0;
        }
    }
    indeks = 0;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            array_main[i][j] = temp[indeks]; //kondisi setelah iterasi
            indeks = indeks+1;
        }
    }
}
