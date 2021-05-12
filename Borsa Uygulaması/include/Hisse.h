#ifndef HISSE_H
#define HISSE_H

#include "stdio.h"
#include "stdlib.h"

struct HISSE{
    char* id;
    char* sembol;
    char* ad;
    double fiyat;
    int idSize;
    int sembolSize; 
    int adSize;

    void (*yoket)(struct HISSE*);
};
typedef struct HISSE* Hisse;

Hisse HisseOlustur(char id[],char sembol[],char ad[],double fiyat,int idSize, int sembolSize, int adSize);
void HisseYoket(Hisse);
#endif