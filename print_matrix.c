/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : 5 (Rombongan E)
* Hari dan Tanggal : Kamis, 16 April 2020
* Asisten (NIM) : Wuri Utami (13217024)
* Nama File : print_matrix.c
* Deskripsi : Fungsi untuk print matrix
*/

void print_matrix(char ** matrix, int max_row, int max_col){
	for(int i = 0; i < max_row; i++){
		for(int j = 0; j < max_col; j++){
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
}
