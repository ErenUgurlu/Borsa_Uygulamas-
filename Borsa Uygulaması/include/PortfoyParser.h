#ifndef PORTFOYPARSER_H
#define PORTFOYPARSER_H

#include "SatirSayici.h"


struct PORTFOYPARSER{
    char** id;
    char** sembol;
    double* maliyet;
    int* adet;
    
    void (*pParserYoket)(struct PORTFOYPARSER*);

};
typedef struct PORTFOYPARSER* PortfoyParser;

PortfoyParser PortfoyParserOlustur();
void PortfoyParserYoket(const PortfoyParser this);
#endif