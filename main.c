#include <stdio.h>

int mainmenu, menukirim, menuterima;

int main(){

printf ("MAIN MENU\n");
printf ("1. Menu Kirim\n2. Menu Terima\n");
printf ("Masukan Pilihan : ");
scanf("%d", &mainmenu);

switch (mainmenu) {

case 1 :
    system("cls");
    printf("Menu Kirim\n");
    printf("1. Input Paket\n2. Cari Paket\n3. Load Paket\n");
    printf ("Masukan Pilihan : ");
    scanf("%d", &menukirim);

    switch (menukirim){
    case 1 :
        printf("Masukan Nama Barang : ");
        scanf("%s", barang);
        printf("\n Masukan Alamat Tujuan : ");
        scanf("%s", alamat);
        printf("\n Masukan Nama Penerima");
        scanf("%s", penerima);
    }
    break;

case 2 :
    system("cls");
    printf("Menu Terima\n");
    printf("1. Terima Paket\n2. Distribusi Paket\n");
    printf ("Masukan Pilihan : ");
    scanf("%d", &menuterima);

    break;
}
return 0;
}
