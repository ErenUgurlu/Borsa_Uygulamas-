#include "../include/Hisse.h"

Hisse HisseOlustur(char id[],char sembol[],char ad[],double fiyat,int idSize, int sembolSize, int adSize)
{
    Hisse this;
    this = (Hisse)malloc(sizeof(struct HISSE));
    this->id = malloc(sizeof(char) * idSize);
    this->sembol = malloc(sizeof(char) * sembolSize);
    this->ad = malloc(sizeof(char) * adSize);
    this->fiyat = fiyat;
    this->yoket = &HisseYoket;
    this->idSize =idSize;
    this->adSize = adSize;
    this->sembolSize = sembolSize;
    int i;
    for (i = 0; i < idSize; i++)
    {
        this->id[i] = id[i];
    }
    for (i = 0; i < sembolSize; i++)
    {
        this->sembol[i] = sembol[i];
    }
    for (i = 0; i < adSize; i++)
    {
        this->ad[i] = ad[i];
    }
    return this;
}
void HisseYoket(const Hisse this){
    if(this == NULL) return;
    free(this->id);
    free(this->ad);
    free(this->sembol);
    free(this);
}