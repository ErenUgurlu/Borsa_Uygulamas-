#include "../include/Emir.h"

Emir EmirOlustur(char id[], char sembol[], char islem[], int adet, int idSize, int sembolSize, int islemSize)
{
    Emir this;
    this = (Emir)malloc(sizeof(struct EMIR));
    this->id = malloc(sizeof(char) * idSize);
    this->sembol = malloc(sizeof(char) * sembolSize);
    this->islem = malloc(sizeof(char) * islemSize);
    this->adet = adet;
    this->EmirYoket = &EmirYoket;
    this->idSize =idSize;
    this->islemSize = islemSize;
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
    for (i = 0; i < islemSize; i++)
    {
        this->islem[i] = islem[i];
    }
    return this;
}
void EmirYoket(const Emir this){
    if(this == NULL) return;
    free(this->id);
    free(this->islem);
    free(this->sembol);
    free(this);
}