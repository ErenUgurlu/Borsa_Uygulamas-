#ifndef EMIR_H
#define EMIR_H

#include "stdio.h"
#include "stdlib.h"

struct EMIR{
    char* id;
    char* sembol;
    char* islem;
    int adet;
    int idSize;
    int sembolSize; 
    int islemSize;

    void (*EmirYoket)(struct EMIR*);
};
typedef struct EMIR* Emir;

Emir EmirOlustur(char id[],char sembol[],char islem[],int adet,int idSize, int sembolSize, int islemSize);
void EmirYoket(Emir);



#endif