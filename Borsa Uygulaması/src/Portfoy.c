#include "../include/Portfoy.h"

Portfoy PortfoyOlustur(char id[],char sembol[],double maliyet,int adet,int idSize, int sembolSize)
{
    Portfoy this;
    this = (Portfoy)malloc(sizeof(struct PORTFOY));
    this->id = malloc(sizeof(char) * idSize);
    this->sembol = malloc(sizeof(char) * sembolSize);
    this->maliyet = maliyet;
    this->adet = adet;
    this->yoket = &PortfoyYoket;
    this->idSize =idSize;
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
    return this;
}
void PortfoyYoket(const Portfoy this){
    if(this == NULL) return;
    free(this->id);
    free(this->sembol);
    free(this);
}