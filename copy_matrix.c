/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : 5 (Rombongan E)
* Hari dan Tanggal : Kamis, 16 April 2020
* Asisten (NIM) : Wuri Utami (13217024)
* Nama File : game-of-life.c
* Deskripsi : Fungsi untuk melakukan copy terhadap matrix yang telah terbentuk
*/

#include<stdio.h>

char** copy_matrix(char ** input_matrix, int row, int column) {
	char **matrix = (char **)malloc(row * sizeof(char *));

	for(int i = 0; i < row; i++) {
		matrix[i] = (char *)malloc(column * sizeof(char));
	}
	for(int i = 0; i < row; i++) {
		for(int j = 0; j < column; j++) {
			matrix[i][j] = input_matrix[i][j];
		}
	}
	return matrix;
}
