/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : 5 (Rombongan E)
* Hari dan Tanggal : Kamis, 16 April 2020
* Asisten (NIM) : Wuri Utami (13217024)
* Nama File : game-of-life.c
* Deskripsi : Fungsi untuk cek kondisi sel di sekitarnya, apakah hidup atau mati
*/

#include <stdio.h>

int adjacent(char ** matrix, int row, int column, int max_row, int max_column) {
	int count = 0;
	int left = column - 1;
	int right = column + 1;
	int bottom = row + 1;
	int top = row - 1;
	if(left == -1) {
		left = max_column-1;
	}
	if(top == -1) {
		top = max_row-1;
	}
	if(right == max_column) {
		right = 0;
	}
	if(bottom == max_row) {
		bottom = 0;
	}

	if(matrix[row][left] == 'X') {
		count++;
	}
	if(matrix[row][right] == 'X') {
		count++;
	}
	if(matrix[top][column] == 'X') {
		count++;
	}
	if(matrix[bottom][column] == 'X') {
		count++;
	}
	if(matrix[top][right] == 'X') {
		count++;
	}
	if(matrix[top][left] == 'X') {
		count++;
	}
	if(matrix[bottom][right] == 'X') {
		count++;
	}
	if(matrix[bottom][left] == 'X') {
		count++;
	}

	return count;
}
