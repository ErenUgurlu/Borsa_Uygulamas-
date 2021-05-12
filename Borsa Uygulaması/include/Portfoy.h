#ifndef PORTFOY_H
#define PORTFOY_H

#include "stdio.h"
#include "stdlib.h"

struct PORTFOY{
    char* id;
    char* sembol;
    double maliyet;
    int adet;
    int idSize;
    int sembolSize; 
    int islemSize;

    void (*yoket)(struct PORTFOY*);
};
typedef struct PORTFOY* Portfoy;

Portfoy PortfoyOlustur(char id[],char sembol[],double maliyet,int adet,int idSize, int sembolSize);
void PortfoyYoket(Portfoy);



#endif