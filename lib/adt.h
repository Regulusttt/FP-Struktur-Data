#ifndef __ADT_
    #define __ADT_
    #define MAX 10

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

struct barangbaru{
    struct barang baru[30];
    char waktu[30][10];
}terima,curr;

#endif