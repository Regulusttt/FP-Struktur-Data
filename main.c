#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "lib/support.h"


int main(){
int partai = 0;
char ulang;
int mainmenu,menukirim,menuterima;
Qcreate();
Screate();

menu:
clear();
header();
printf ("MAIN MENU\n");
printf ("1. Menu Kirim\n2. Menu Terima\n3. Exit\n");
printf ("Masukan Pilihan : ");
scanf("%d", &mainmenu);


switch (mainmenu) {

case 1 :
    kirim :
    clear();
    printf("Menu Kirim\n");
    printf("1. Input Paket\n2. Cari Paket\n3. Load Paket\n4. Kembali ke Menu Utama\n");
    printf ("Masukan Pilihan : ");
    scanf("%d", &menukirim);

    switch (menukirim){
    case 1 :
        isi:
        clear();
        isi();
        puts("Paket berhasil diinput");
        getch();
        goto kirim;
        break;


    case 2 :
        search();
        puts("Tekan Enter Untuk Kembali");
        getch();
        goto kirim;
        break;

    case 3 :
    if(s.top==MAX-1){
        puts("Truk sudah penuh! Silahkan kirim truk ke gudang tujuan!");
        getch();
    }
    else if (partai==3){
        puts("Maksimal partai per-hari sudah melebihi kuota!");
        getch();
    } else if (QisEmpty()==1){
        puts("Tidak ada paket di gudang yang dapat diload ke Truk");
        getch();
    } else {
        Swap();
        Qdisplay();
        Sdisplay();
        puts("Tekan Enter Untuk Kembali");
        getch();
    }
        goto kirim;
        break;

    case 4 :
        goto menu;
        break;
    }
break;

case 2 :
    acc:
    clear();
    printf("Menu Terima\n");
    printf("1. Terima Paket\n2. Distribusi Paket\n3. Kembali ke Menu Utama\n");
    printf ("Masukan Pilihan : ");
    scanf("%d", &menuterima);
switch(menuterima){
    case 1:
    if (partai==3){
        puts("Maksimal partai per-hari sudah melebihi kuota!");
        getch();
    }
    else if (SisEmpty()==1){
        puts("Tidak ada paket didalam Truk");
        getch();
    } else {
        pop();
        puts("\nSemua paket didalam truk sudah dikeluarkan");
        getch();
        partai++;
    }
        goto acc;
        break;

    case 2:
        sorting();
        rute();
        getch();
        getch();
        goto acc;
        break;

    case 3:
        goto menu;
        break;
}
    break;
}
return 0;
}
