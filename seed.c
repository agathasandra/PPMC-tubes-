#include<stdio.h>
#include<stdlib.h>

void seed(){
    FILE*fptr;

    char a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q;
    int pilih;

    printf("Berikut List Pilihan Seed: \n");
    printf("[1] diehard                          [10] Quilt square\n");
    printf("[2] Dinner Table                     [11] R-pentomino\n");
    printf("[3] Fish                             [12] Seeds\n");
    printf("[4] Flower                           [13] Simple\n");
    printf("[5] Format                           [14] Snowflake\n");
    printf("[6] Glider                           [15] Spiral\n");
    printf("[7] Glider explosion                 [16] Stable Plateau\n");
    printf("[8] Gosper's glider gun              [17] Tic tac toe\n");
    printf("[9] My colony \n");

    printf("\nPilihan nomor seed yang diinginkan: ");
    scanf("%d", &pilih);

    switch(pilih){
    case 1:
        printf("\n");
        fptr = fopen("diehard.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        a = fgetc(fptr);
        while (a != EOF){
            printf("%c", a);
            a = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 2:
        printf("\n");
        fptr = fopen("dinner-table.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        b = fgetc(fptr);
        while (b != EOF){
            printf("%c", b);
            b = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 3:
        printf("\n");
        fptr = fopen("fish.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        c = fgetc(fptr);
        while (c != EOF){
            printf("%c", c);
            c = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 4:
        printf("\n");
        fptr = fopen("flower.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        d = fgetc(fptr);
        while (d != EOF){
            printf("%c", d);
            d = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 5:
        printf("\n");
        fptr = fopen("format.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        e = fgetc(fptr);
        while (e != EOF){
            printf("%c", e);
            e = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 6:
        printf("\n");
        fptr = fopen("glider.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        f = fgetc(fptr);
        while (f != EOF){
            printf("%c", f);
            f = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 7:
        printf("\n");
        fptr = fopen("glider-explosion.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        g = fgetc(fptr);
        while (g != EOF){
            printf("%c", g);
            g = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 8:
        printf("\n");
        fptr = fopen("glider-gun.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        h = fgetc(fptr);
        while (h != EOF){
            printf("%c", h);
            h = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 9:
        printf("\n");
        fptr = fopen("mycolony.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        i = fgetc(fptr);
        while (i != EOF){
            printf("%c", i);
            i = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 10:
        printf("\n");
        fptr = fopen("quilt-square.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        j = fgetc(fptr);
        while (j != EOF){
            printf("%c", j);
            j = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 11:
        printf("\n");
        fptr = fopen("rpent.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        k = fgetc(fptr);
        while (k != EOF){
            printf("%c", k);
            k = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 12:
        printf("\n");
        fptr = fopen("seeds.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        l = fgetc(fptr);
        while (l != EOF){
            printf("%c", l);
            l = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 13:
        printf("\n");
        fptr = fopen("simple.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        m = fgetc(fptr);
        while (m != EOF){
            printf("%c", m);
            m = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 14:
        printf("\n");
        fptr = fopen("snowflake.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        n = fgetc(fptr);
        while (n != EOF){
            printf("%c", n);
            n = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 15:
        printf("\n");
        fptr = fopen("spiral.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        o = fgetc(fptr);
        while (o != EOF){
            printf("%c", o);
            o = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 16:
        printf("\n");
        fptr = fopen("stableplateau.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        p = fgetc(fptr);
        while (p != EOF){
            printf("%c", p);
            p = fgetc(fptr);
        }
        fclose(fptr);
        break;
    case 17:
        printf("\n");
        fptr = fopen("tictactoe.txt", "r");
        if(fptr == NULL){
            printf("File error");
            exit(0);
        }
        q = fgetc(fptr);
        while (q != EOF){
            printf("%c", q);
            q = fgetc(fptr);
        }
        fclose(fptr);
        break;
    }
    return 0;
}
