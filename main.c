#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define size 2

int hash[size];
int i,hasil=-1;
struct Database {
    int b;
    int c;
    int pin1[50];
    int pin;
    int d;
   long long nomer;
   char score[size];
} data[50], curr;



void init()
{
    int i;
    for(i = 0; i < size; i++)
        hash[i] = -1;
}

void insert(int value)
{
    int key = value % size;

    if(hash[key] == -1)
    {
        hash[key] = value;
        printf("\n");
    }
    else
    {
        printf("Collision : hash[%d] has element %d already!\n",key,hash[key]);
        printf("Unable to insert %d\n",value);
    }
}

void search(int value)
{
    int key = value % size;
    if(hash[key] == value) {
        printf("Nomor terverifikasi\n");
    }
    else {
        printf("Nomor anda tidak terdata\n");
        return main();
    }
}

int inspin()
{
    printf("Masukkan Pin Anda : ");
 scanf("%s",&data->pin);
 printf("====================================\n");
 if(hasil == 0 ){
     printf("PIN benar");
 }
 else {
     printf("PIN salah");
     return inspin();
 }
}
int main ()
{
    int pin1,pin2;
    FILE *fp;
    fp = fopen("pin.txt","r");
    while(!feof(fp)){
        fscanf(fp,"%lld %d",&data[i].nomer,&data[i].pin1);
        i++;
    }
    for(i=0;i<size;i++){
    printf("%lld %d\n",data[i].nomer,data[i].pin1);
    }
}
