#include "stdio.h"

#include "../include/Banka.h"
#include "../include/EmirParser.h"
int main()
{

    Banka bank;
    bank = BankaOlustur();
    bank->KarZararHesap(bank);

    return 0;
}