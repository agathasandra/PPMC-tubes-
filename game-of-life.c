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

void tick(char **array_main,int m,int n);
void display(char **array_main,int baris,int kolom);
char** readFile(int * max_row, int * max_col);

int main(){
    int aksi, baris, kolom, iterasi, i, loop;
    char **array_main, baru;

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

    array_main=readFile(&baris,&kolom);
    if (array_main!=NULL){
        display(array_main,baris,kolom);
    }

    while (aksi!=3 && baris!=99999 && kolom!=99999){
    	printf("\n\nBerikut adalah beberapa aksi yang dapat dipilih: \n");
    	printf("1. Tick\n");
    	printf("2. Animate\n");
    	printf("3. Quit\n\n");
    	printf("Pilihan nomor aksi yang diinginkan: ");
    	scanf("%d", &aksi);

	if (aksi==1){
            tick(array_main,baris,kolom);
            display(array_main,baris,kolom);
        }
	else if (aksi == 2){
	    printf("Masukkan jumlah iterasi: ");
	    scanf("%d",iterasi);
            for(i=0;i<iterasi;i++){
                tick(array_main,baris,kolom);
                display(array_main,baris,kolom);
            }
	}
	else if (aksi==3){
            loop=1;
            while(loop==1){
                printf("Apakah anda mau memasukkan file seed baru?(Y/N)\n");
                scanf(" %c",&baru);
                if (baru=='Y' || baru=='y'){
                    free(array_main);
                    pilihan=99;
                    loop=0;
                    array_main=readFile(&baris,&kolom);
                    if (array_main!=NULL){
                        display(array_main,baris,kolom);
                    }
                }
                else if (baru=='N' || baru=='n'){
                    printf("Selamat tinggal");
                    loop=0;
                }
                else{
                    printf("input salah.\n");
                }
            }
        }
	else{
		printf("pilihan invalid.\n");
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

void tick(char **array_main,int m,int n){
    int i,j,k,kounter=0,atas,bawah,kanan,kiri,indeks=0;
    char temp2[8];
    char *temp=(char *)malloc(m*n*sizeof(char));
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if (i==0){
                atas=(m-1);
                bawah=i+1;
            }
            else if (i==(m-1)){
                atas=i-1;
                bawah=0;
            }
            else{
                atas=i-1;
                bawah=i+1;
            }
            if (j==0){
                kiri=(n-1);
                kanan=j+1;
            }
            else if (j==(n-1)){
                kiri=j-1;
                kanan=0;
            }
            else{
                kiri=j-1;
                kanan=j+1;
            }
            temp2[0]=array_main[atas][kiri];
            temp2[1]=array_main[atas][j];
            temp2[2]=array_main[atas][kanan];
            temp2[3]=array_main[i][kiri];
            temp2[4]=array_main[i][kanan];
            temp2[5]=array_main[bawah][kiri];
            temp2[6]=array_main[bawah][j];
            temp2[7]=array_main[bawah][kanan];
            for (k=0;k<8;k++){
                if (temp2[k]=='X'){
                    kounter=kounter+1;
                }
            }
            if (array_main[i][j]=='X'){
                if (kounter==2 || kounter==3){
                    temp[indeks]='X';
                }
                else{
                    temp[indeks]='-';
                }
                indeks=indeks+1;
            }
            else if (array_main[i][j]=='-'){
                if (kounter==3){
                    temp[indeks]='X';
                }
                else{
                    temp[indeks]='-';
                }
                indeks=indeks+1;
            }
            kounter=0;
        }
    }
    indeks=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            array_main[i][j]=temp[indeks];
            indeks=indeks+1;
        }
    }
}

char** readFile(int * max_row, int * max_col) {
	char read,nama_file[50];
	int row = 0;
	int column = 0;
	int stop = 0;
	FILE* file;
    int row_now = 0;

    printf("Daftar file seed:\n");
    printf("1. diehard.txt \t\t\t\t 2. dinner_table.txt\n");
    printf("3. fish.txt \t\t\t\t 4. flower.txt\n");
    printf("5. format.txt \t\t\t\t 6. glider.txt\n");
    printf("7. glider_explosion.txt \t\t 8. glider_gun.txt\n");
    printf("9. mycolony.txt \t\t\t 10. quilt_square.txt\n");
    printf("11. rpent.txt \t\t\t\t 12. seeds.txt\n");
    printf("13. simple.txt \t\t\t\t 14. snowflake.txt\n");
    printf("15. spiral.txt \t\t\t\t 16. stableplateau.txt\n");
    printf("17. tictactoe.txt\n");
    input_nama_file:
    printf("Masukkan nama file seed (masukkan q untuk keluar): ");
    scanf("%s",nama_file);
    if (strcmp(nama_file,"q")==0){
        printf("Terima kasih");
        *max_row=99999;
        *max_col=99999;
        return(NULL);
    }
    file=fopen(nama_file,"r");
    if (file==NULL){
        printf("File cant open\n");
        goto input_nama_file;
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


