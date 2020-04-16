/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : 5 (Rombongan E)
* Hari dan Tanggal : Selasa, 14 April 2020
* Asisten (NIM) : Wuri Utami (13217024)
* Nama File : seed.c
* Deskripsi : Fungsi untuk print file seed ke layar
*/

#include<stdio.h>
#include<stdlib.h>

void seed(char *** matrix, char *** check_matrix, int * max_row, int * max_col){
	char pilih[50];

    printf("Berikut List Pilihan Seed: \n");
    printf("[1] diehard.txt                          [10] quilt-square.txt\n");
    printf("[2] dinner-table.txt                     [11] rpent.txt\n");
    printf("[3] fish.txt                             [12] seeds.txt\n");
    printf("[4] flower.txt                           [13] simple.txt\n");
    printf("[5] format.txt                           [14] snowflake.txt\n");
    printf("[6] glider.txt                           [15] spiral.txt\n");
    printf("[7] glider-explosion.txt                 [16] stableplateau.txt\n");
    printf("[8] glider-gun.txt                       [17] tictactoe.txt\n");
    printf("[9] mycolony.txt \n");

    printf("\nSeed yang diinginkan: ");
    gets(pilih);
    *matrix = readFile(pilih, max_row, max_col);
    *check_matrix = copy_matrix(*matrix, *max_row, *max_col);
    printf("%d\n", *max_row);
    printf("%d\n", *max_col);
    print_matrix(*matrix, *max_row, *max_col);
}
