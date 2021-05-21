#include <stdio.h>
#define MAX 10

static int i=0;

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
        printf("%s Masuk\n", q.data[i].resi);
    }
i++;
}

void Swap(){
int x=0;
int counter;

    if(s.top==MAX-1){
        puts("Mobil Sudah Penuh! Silahkan Kirim Mobil ke Gudang Tujuan!");
    }else {
        s.top++;
        s.data[s.top]=q.data[x];

        temp.data[i]=q.data[q.head];
    for(x=q.head;x<=q.tail-1;x++){
        q.data[x]=q.data[x+1];
        counter++;
    }
    q.tail--;
    return temp;
    }

}

void Sdisplay(){
    puts("Data Stack : ");
    for (int x=s.top;x>0;x--){
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

int main(){
int jumdat=0;
int counter = 0;
char ulang;

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
    printf("1. Input Paket\n2. Cari Paket\n3. Load Paket\n");
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

        printf("Isi Data Lagi? : ");
        scanf("%s", &ulang);
        fflush(stdin);
        if (ulang == 'y'){
        goto isi;
        }
        break;

    case 2 :
        cari :
        break;

    case 3 :
        Swap();
        break;
}

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
