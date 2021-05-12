#ifndef HISSEPARSER_H
#define HISSEPARSER_H

#include "SatirSayici.h"


struct HISSEPARSER{
    char** id;
    char** sembol;
    char** ad;
    double* fiyat;
    
    void (*hParserYoket)(struct HISSEPARSER*);

};
typedef struct HISSEPARSER* HisseParser;

HisseParser HisseParserOlustur();
void HisseParserYoket(const HisseParser this);
#endif