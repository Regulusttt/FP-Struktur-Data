#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include "support.h"

int jumdat=0;
static int i=0;
int z=0;
char filename_string[20];

void isi(){
        jumdat++;
        for (;i<jumdat;){
            printf("Masukan Nomor Resi      : ");
            scanf("%s", barang[i].resi);
            printf("Masukan Nama Pengirim   : ");
            scanf("%s", barang[i].pengirim);
            printf("Masukan Nama Penerima   : ");
            scanf("%s", barang[i].penerima);
            printf("Masukan Alamat Penerima : ");
            scanf("%s", barang[i].alamat);
            printf("Masukan Nama Barang     : ");
            scanf("%s", barang[i].jenis);
            printf ("\n");
            Qenqueue();
        }
}

int waktuterima() {
time_t t = time(NULL);
    struct tm local_time = *localtime(&t);

    int hour = local_time.tm_hour;
    int minute = local_time.tm_min;
    int second = local_time.tm_sec;

    sprintf(filename_string, "%02d:%02d:%02d", hour, minute, second);
    return 0;
}

void clear() {
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

void header(){
    puts("====================================================");
    puts("            Final Project Struktur Data             ");
    puts("                      Case 3                        ");
    puts("                   Kelompok 5E                      ");
    puts("====================================================");
    puts("Muhammad Arrysatrya Yusuf Putranda       2008561097 ");
    puts("I Made Teja Sarmandana                   2008561098 ");
    puts("Revi Valen Sumendap                      2008561099 ");
    puts("Putu Bagus Dio Pranata                   2008561100 ");
    puts("====================================================\n");
}

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

int SisEmpty(){
    if(s.top==-1)
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
        puts("Truk sudah penuh! Silahkan kirim truk ke gudang tujuan!");
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
        printf("Paket dengan nomor resi %s sudah dikeluarkan dari truk\n", terima.baru[x].resi);
        getch();
    }
}

void Sdisplay(){
    puts("\nPaket Dalam Truk : ");
    for (int x=s.top;x>=0;x--){
        printf("Nomor Resi      : %s\n", s.data[x].resi);
        printf("Nama Pengirim   : %s\n", s.data[x].pengirim);
        printf("Nama Penerima   : %s\n", s.data[x].penerima);
        printf("Alamat Penerima : %s\n", s.data[x].alamat);
        printf("Nama Barang     : %s\n", s.data[x].jenis);
        printf("\n");
    }
}

void Qdisplay(){
    if(QisEmpty()==0){
    puts("Data Paket Gudang : ");
    for (int x=q.head;x<=q.tail;x++){
        printf("Nomor Resi      : %s\n", q.data[x].resi);
        printf("Nama Pengirim   : %s\n", q.data[x].pengirim);
        printf("Nama Penerima   : %s\n", q.data[x].penerima);
        printf("Alamat Penerima : %s\n", q.data[x].alamat);
        printf("Nama Barang     : %s\n", q.data[x].jenis);
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
            puts("Resi Ditemukan\n");
            printf("Nomor Resi      : %s\n", barang[x].resi);
            printf("Nama Pengirim   : %s\n", barang[x].pengirim);
            printf("Nama Penerima   : %s\n", barang[x].penerima);
            printf("Alamat Penerima : %s\n", barang[x].alamat);
            printf("Nama Barang     : %s\n", barang[x].jenis);
            break;
        }
        else puts("Resi Tidak Ditemukan");
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

void rute(){
    puts ("Urutan Paket yang perlu dikirim : \n");
        for(int x=0;x<z;x++){
            printf("Nomor Resi      : %s\n", terima.baru[x].resi);
            printf("Nama Pengirim   : %s\n", terima.baru[x].pengirim);
            printf("Nama Penerima   : %s\n", terima.baru[x].penerima);
            printf("Alamat Penerima : %s\n", terima.baru[x].alamat);
            printf("Nama Barang     : %s\n", terima.baru[x].jenis);
            printf("Waktu Masuk     : %s\n\n", terima.waktu[x]);
        }
}