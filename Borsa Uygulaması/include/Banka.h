#ifndef BANKA_H
#define BANKA_H

#include "../include/SatirSayici.h"
#include "../include/EmirParser.h"
#include "../include/HisseParser.h"
#include "../include/PortfoyParser.h"
#include "../include/Emir.h"
#include "../include/Hisse.h"
#include "../include/Portfoy.h"


struct BANKA{
    EmirParser eParser;
    Emir* emirler;
    HisseParser hParser;
    Hisse* hisseler;
    PortfoyParser pParser;
    Portfoy* portfoyler;

    void (*BankaYoket)(struct BANKA*);
    void (*KarZararHesap)(struct BANKA*);
    int (*portfoyBul)(char*,struct BANKA*);
    int (*hisseBul)(char*,struct BANKA*);

};
typedef struct BANKA* Banka;
Banka BankaOlustur();
void KarZararHesap(Banka banka);
int portfoyBul(char semboller[], Banka banka);
int hisseBul(char semboller[], Banka banka);
void BankaYoket(const Banka this);
#endif