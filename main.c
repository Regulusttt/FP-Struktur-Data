#include <stdio.h>
#include <string.h>
#define MAX 10
#include <time.h>

int jumdat=0;
static int i=0;
int z=0;
char filename_string[20];

int waktuterima() {
time_t t = time(NULL);
    struct tm local_time = *localtime(&t);

    int hour = local_time.tm_hour;
    int minute = local_time.tm_min;
    int second = local_time.tm_sec;

    sprintf(filename_string, "%02d:%02d:%02d", hour, minute, second);
    return 0; }

struct barang{
    char pengirim[50], penerima[50], alamat[50];
    char resi[10];
    char jenis[50];
}barang[30];

typedef struct {
    struct barang data[30];
    int head, tail;
} Queue;
Queue q;

typedef struct {
    struct barang data[10];
    int top;
}Stack;
Stack s;

typedef struct{
    struct barang data[10];
}Temp;
Temp temp;

struct waktuwaktu{
    char waktu[20]
}Waktu[20];

struct barangbaru{
    struct barang baru[30];
    char waktu[30][10];
}terima,curr;

void Qcreate(){
q.head=q.tail=-1;
}

void Screate(){
    s.top=-1;
}

int QisEmpty(){
    if(q.tail==-1)
        return 1;
    else
        return 0;
}

int QisFull(){
    if(q.tail==MAX-1)
        return 1;
    else
        return 0;
}

void Qenqueue(){
    if(QisEmpty()==1){
        q.head=q.tail=0;
        q.data[q.tail]=barang[i];
        }
    else if (QisFull()==0){
        q.tail++;
        q.data[q.tail]=barang[i];
    }
i++;
}

void Swap(){
int x;
int c=0;
    if(s.top==MAX-1){
        puts("Mobil Sudah Penuh! Silahkan Kirim Mobil ke Gudang Tujuan!");
    }
    else while(c<=10 && q.head <= q.tail) {
        x=q.head;
        s.top++;
        s.data[s.top]=q.data[x];

        temp.data[x]=q.data[q.head];
	    for(;x<=q.tail-1;x++){
	        q.data[x]=q.data[x+1];
	    }
	    q.tail--;
	    c++;
    }
        return temp.data[x];

}

void pop(){
int x;
int y;
y=s.top;


        for (x=0;x<=y;x++){
        waktuterima();
        terima.baru[x] = s.data[s.top];
        strcpy(terima.waktu[x],filename_string);
        z++;
        s.top--;
        getch();
        }

}

void Sdisplay(){
    puts("Data Stack : ");
    for (int x=s.top;x>=0;x--){
        printf("Nomor Resi : %s\n", s.data[x].resi);
        printf("Nama Pengirim : %s\n", s.data[x].pengirim);
        printf("Nama Penerima : %s\n", s.data[x].penerima);
        printf("Alamat Penerim : %s\n", s.data[x].alamat);
        printf("Nama Barang : %s\n", s.data[x].jenis);
        printf("\n");
    }
}

void Qdisplay(){
    if(QisEmpty()==0){
    puts("Data Queue : ");
    for (int x=q.head;x<=q.tail;x++){
        printf("Nomor Resi : %s\n", q.data[x].resi);
        printf("Nama Pengirim : %s\n", q.data[x].pengirim);
        printf("Nama Penerima : %s\n", q.data[x].penerima);
        printf("Alamat Penerim : %s\n", q.data[x].alamat);
        printf("Nama Barang : %s\n", q.data[x].jenis);
        printf("\n");
    }
}
}

void search(){
    char cari[10];
    int x;
    printf("Masukan Resi : ");
    scanf("%s", cari);
    getchar();

    for(x=0;x<jumdat;x++){
        if (strcmp(barang[x].resi, cari)==0)
        {
            printf("Resi Ditemukan\n");
            printf("Nomor Resi : %s\n", barang[x].resi);
            printf("Nama Pengirim : %s\n", barang[x].pengirim);
            printf("Nama Penerima : %s\n", barang[x].penerima);
            printf("Alamat Penerima : %s\n", barang[x].alamat);
            printf("Nama Barang : %s\n", barang[x].jenis);
            break;
        }
        else printf("Resi Tidak Ditemukan");
    }
}

void sorting(){
    for (int m = 1; m < z; m++)
        for (int n = 0; n < z - m; n++) {
            if (strcmp(terima.waktu[n], terima.waktu[n+1]) > 0) {
            temp.data[n] = terima.baru[n];
            terima.baru[n] = terima.baru[n+1];
            terima.baru[n+1] = temp.data[n];
         }
      }
}

int main(){
int counter = 0;
char ulang;
int mainmenu,menukirim,menuterima;
Qcreate();
Screate();

menu:
system("cls");
printf ("MAIN MENU\n");
printf ("1. Menu Kirim\n2. Menu Terima\n3. Exit\n");
printf ("Masukan Pilihan : ");
scanf("%d", &mainmenu);


switch (mainmenu) {

case 1 :
    kirim :
    system("cls");
    printf("Menu Kirim\n");
    printf("1. Input Paket\n2. Cari Paket\n3. Load Paket\n4. Kembali ke Menu Utama\n");
    printf ("Masukan Pilihan : ");
    scanf("%d", &menukirim);

    switch (menukirim){
    case 1 :
        isi:
        system("cls");
        jumdat++;
        for (;i<jumdat;){
            printf("Masukan Nomor Resi: ");
            scanf("%s", barang[i].resi);
            printf("Masukan Nama Pengirim: ");
            scanf("%s", barang[i].pengirim);
            printf("Masukan Nama Penerima: ");
            scanf("%s", barang[i].penerima);
            printf("Masukan Alamat : ");
            scanf("%s", barang[i].alamat);
            printf("Masukan Nama Barang : ");
            scanf("%s", barang[i].jenis);
            printf ("\n");
            Qenqueue();
        }
        puts("Paket Berhasil Diinput");
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
        Swap();
        Qdisplay();
        Sdisplay();
        puts("Tekan Enter Untuk Kembali");
        getch();
        goto kirim;
        break;

    case 4 :
        goto menu;
        break;
    }
break;

case 2 :
    acc:
    system("cls");
    printf("Menu Terima\n");
    printf("1. Terima Paket\n2. Distribusi Paket\n3. Kembali ke Menu Utama");
    printf ("Masukan Pilihan : ");
    scanf("%d", &menuterima);
switch(menuterima){
    case 1:
        Swap();
        goto acc;
        break;

    case 2:
        sorting();
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
