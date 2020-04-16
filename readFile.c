/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
*  MODUL 9 – TUGAS BESAR
*  Kelompok         : 5 (Rombongan E)
*  Hari dan Tanggal : Kamis, 16 April 2020
*  Asisten (NIM)    : Wuri Utami (13217024)
*  Nama File        : readFile.c
*  Deskripsi        : Fungsi untuk membaca external files dan memasukkannya ke dalam matrix
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

char** readFile(int * max_row, int * max_col) {
	//Deklarasi Variabel
	char read,nama_file[50];
	int row = 0;
	int column = 0;
	int stop = 0;
	FILE* file;
    int row_now = 0;

    printf("Berikut List Pilihan Seed: \n");
    printf("[1] diehard.txt                          [10] quilt-square.txt\n");
    printf("[2] dinner-table.txt                     [11] rpent.txt\n");
    printf("[3] fish.txt                             [12] seeds.txt\n");
    printf("[4] flower.txt                           [13] simple.txt\n");
    printf("[5] format.txt                           [14] snowflake.txt\n");
    printf("[6] glider.txt                           [15] spiral.txt\n");
    printf("[7] glider-explosion.txt                 [16] stableplateau.txt\n");
    printf("[8] glider-gun.txt                       [17] tictactoe.txt\n");
    printf("[9] mycolony.txt                         [18] q (keluar)\n");

    input_nama_file:
    printf("\nMasukkan nama file seed: ");
    scanf("%s", nama_file);

    if (strcmp(nama_file,"q") == 0){ //bila user memasukkan input q, maka program akan berhenti dan user keluar
        printf("\nTerima kasih\n");
        *max_row = 99999;
        *max_col = 99999;
        return(NULL);
    }

    file = fopen(nama_file, "r");
    if (file==NULL){
        printf("File cant open\n"); //Jika user memasukkan nama file yang tidak ada
        goto input_nama_file; //user akan kembali memasukkan input file hingga input benar
    }

	read = fgetc(file);
	while (read != '\n'){
		row = (row * 10) + (int)read - (int)'0';
		read = fgetc(file);
	}

	read = fgetc(file);
	while (read != '\n'){
		column = (column * 10) + (int)read - (int)'0';
		read = fgetc(file);
	}
    //Mengubah atau memasukkan input ke dalam bentuk array 2x2
	char **matrix = (char **)malloc(row * sizeof(char *));

	for(int i = 0; i < row; i++) {
		matrix[i] = (char *)malloc(column * sizeof(char));
	}

	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) {
			read = fgetc(file);
			if(read == '\n'){
				read = fgetc(file);
			}
			matrix[i][j] = read;
		}
    }
    *max_row = row;
    *max_col = column;
    fclose(file);
    return matrix;
}
