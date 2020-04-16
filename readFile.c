/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : 5 (Rombongan E)
* Hari dan Tanggal : Kamis, 16 April 2020
* Asisten (NIM) : Wuri Utami (13217024)
* Nama File : game-of-life.c
* Deskripsi : Fungsi untuk membaca external files dan memasukkannya ke dalam matrix
*/

#include <stdio.h>
#include<string.h>
#include <stdlib.h>

char** readFile(char * filename, int * max_row, int * max_col) {
	char read;
	int row = 0;
	int column = 0;
	int stop = 0;
	FILE* file;
    file = fopen(filename, "r");
    int row_now = 0;

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
    return matrix;
}
