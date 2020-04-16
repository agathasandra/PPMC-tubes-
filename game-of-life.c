/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 9 – TUGAS BESAR
* Kelompok : 5 (Rombongan E)
* Hari dan Tanggal : Kamis, 16 April 2020
* Asisten (NIM) : Wuri Utami (13217024)
* Nama File : game-of-life.c
* Deskripsi : Program utama yang mensimulasikan game of life
*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

char** readFile(char * filename, int * max_row, int * max_col){
	char read;
	int row = 0, column = 0, stop = 0;
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

	for(int i = 0; i < row; i++){
		matrix[i] = (char *)malloc(column * sizeof(char));
	}

	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
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

int adjacent(char ** matrix, int row, int column, int max_row, int max_column){
	int count = 0;
	int left = column - 1;
	int right = column + 1;
	int bottom = row + 1;
	int top = row - 1;
	if(left == -1){
		left = max_column-1;
	}
	if(top == -1){
		top = max_row-1;
	}
	if(right == max_column){
		right = 0;
	}
	if(bottom == max_row){
		bottom = 0;
	}

	if(matrix[row][left] == 'X'){
		count++;
	}
	if(matrix[row][right] == 'X'){
		count++;
	}
	if(matrix[top][column] == 'X'){
		count++;
	}
	if(matrix[bottom][column] == 'X'){
		count++;
	}
	if(matrix[top][right] == 'X'){
		count++;
	}
	if(matrix[top][left] == 'X'){
		count++;
	}
	if(matrix[bottom][right] == 'X'){
		count++;
	}
	if(matrix[bottom][left] == 'X'){
		count++;
	}
	return count;
}

void print_matrix(char ** matrix, int max_row, int max_col){
	for(int i = 0; i < max_row; i++){
		for(int j = 0; j < max_col; j++){
			printf("%c", matrix[i][j]);
		}
		printf("\n");
	}
}

char** copy_matrix(char ** input_matrix, int row, int column){
	char **matrix = (char **)malloc(row * sizeof(char *));

	for(int i = 0; i < row; i++){
		matrix[i] = (char *)malloc(column * sizeof(char));
	}
	for(int i = 0; i < row; i++){
		for(int j = 0; j < column; j++){
			matrix[i][j] = input_matrix[i][j];
		}
	}
	return matrix;
}

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

void display(char **array_main,int baris,int kolom);
void tick(char **array_main,int baris,int kolom);

int main(){
    int max_row, max_col, aksi, baris, kolom, iterasi, i, loop;
	char ** matrix, ** check_matrix, **array_main, baru;

    printf("---------------------------------------- SELAMAT DATANG DI PERMAINAN GAME OF LIFE ----------------------------------------\n\n");
    printf("Pada permainan ini, kita akan melakukan simulasi mengenai kondisi hidup dan mati pada sel.\n");
    printf("Pada sel akan ada 2 buah karakter.\n");
    printf("Karakter '-' menandakan kondisi sel yang mati dan karakter 'X' menandakan kondisi sel yang hidup.\n");
    printf("Permainan ini ditentukan oleh kondisi awal permainan, yaitu berdasarkan posisi sel pada setiap seed.\n\n");
    printf("Adapun beberapa peraturan yang berlaku pada permainan ini, yaitu: \n");
    printf("1. Jika sel hidup memiliki kurang dari 1 tetangga yang hidup, maka sel tersebut akan mati/ underpopulation.\n");
    printf("2. Jika sel hidup memiliki 2 tetangga yang hidup, maka sel tersebut akan tetap hidup pada iterasi selanjutnya /next generation.\n");
    printf("3. Jika sel mati memiliki 3 tetangga yang hidup, maka sel menjadi hidup pada iterasi selanjutnya /reproduction.\n");
    printf("4. Jika sel hidup memiliki 4 tetangga yang hidup, maka sel tersebut akan mati pada iterasi selanjutnya /overpopulation.\n\n");
    printf("Mari kita mulai permainannya!\n");

    seed(&matrix, &check_matrix, &max_row, &max_col);

    while (aksi!=3){
    printf("\n\nBerikut adalah beberapa aksi yang dapat dipilih: \n");
    printf("1. Tick\n");
    printf("2. Animate\n");
    printf("3. Quit\n\n");
    printf("Pilihan nomor aksi yang diinginkan: ");
    scanf("%d", &aksi);

	if (aksi==1){
        for(int i = 0; i < max_row; i++){
            for(int j = 0; j < max_col; j++){
                int count_adj = adjacent(check_matrix, i, j, max_row, max_col);
                if(count_adj == 1){
                    matrix[i][j] = '-';
                }
                else if(count_adj == 3){
                    matrix[i][j] = 'X';
                }
                else if(count_adj >= 4){
                    matrix[i][j] = '-';
                }
            }
        }
        printf("\n");
        print_matrix(matrix, max_row, max_col);
	}
	if (aksi == 2){
	    printf("Masukkan jumlah iterasi: ");
	    scanf("%d",iterasi);
            for(i=0;i<iterasi;i++){
                for(int i = 0; i < max_row; i++){
                    for(int j = 0; j < max_col; j++){
                        int count_adj = adjacent(check_matrix, i, j, max_row, max_col);
                            if(count_adj == 1){
                                matrix[i][j] = '-';
                            }
                            else if(count_adj == 3){
                                matrix[i][j] = 'X';
                            }
                            else if(count_adj >= 4){
                                matrix[i][j] = '-';
                            }
                    }
                }
                printf("\n");
                print_matrix(matrix, max_row, max_col);
                display(array_main,baris,kolom);
            }
	}
	else if (aksi==3){
            loop=1;
            while(loop==1){
                printf("Apakah anda mau memasukkan file seed baru?(Y/N)\n");
                scanf(" %c",&baru);
                if (baru=='Y'){
                    seed(&matrix, &check_matrix, &max_row, &max_col);
                    aksi=99;//agar loop kembali berjalan
                    loop=0;
                }
                else if (baru=='N'){
                    printf("Selamat Tinggal");
                    loop=0;
                }
                else{
                    printf("pilihan invalid.\n");
                }
            }
        }
    }
	return 0;
}

void display(char **array_main,int baris,int kolom){
    int ms=250,i,j;
    clock_t start=clock();
    while(clock()<start+ms);
    system("cls");
    for(i=0;i<baris;i++){
        for(j=0;j<kolom;j++){
            printf("%c",array_main[i][j]);
        }
        printf("\n");
    }
}
