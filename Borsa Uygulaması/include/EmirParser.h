#ifndef EMIRPARSER_H
#define EMIRPARSER_H

#include "SatirSayici.h"


struct EMIRPARSER{

    char **id; 
    char **sembol; 
    char **islem;
    int *adet;

    void (*eParserYoket)(struct EMIRPARSER*);
};
typedef struct EMIRPARSER* EmirParser;

EmirParser EmirParserOlustur();
void EmirParserYoket(const EmirParser this);
#endif