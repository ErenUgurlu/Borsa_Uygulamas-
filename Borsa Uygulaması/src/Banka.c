#include "../include/Banka.h"
#include <string.h>

Banka BankaOlustur()
{
    Banka this;
    this = (Banka)malloc(sizeof(struct BANKA));
    this->emirler = malloc(sizeof(Emir) * EmirSayisi());
    this->hisseler = malloc(sizeof(Hisse) * HisseSayisi());
    this->portfoyler = malloc(sizeof(Portfoy) * PortfoySayisi());
    this->BankaYoket = &BankaYoket;
    this->hisseBul = &hisseBul;
    this->portfoyBul = &portfoyBul;
    this->KarZararHesap = &KarZararHesap;
    this->eParser = EmirParserOlustur();
    this->hParser = HisseParserOlustur();
    this->pParser = PortfoyParserOlustur();
    int i;
    int j = 2;

    for (i = 0; i < EmirSayisi(); i++)
    {
        this->emirler[i] = EmirOlustur(this->eParser->id[j],
                                       this->eParser->sembol[j],
                                       this->eParser->islem[j],
                                       this->eParser->adet[j],
                                       strlen(this->eParser->id[j]),
                                       strlen(this->eParser->sembol[j]),
                                       strlen(this->eParser->islem[j]));

        j++;
    }
    j = 2;
    for (i = 0; i < HisseSayisi(); i++)
    {
        this->hisseler[i] = HisseOlustur(this->hParser->id[j],
                                         this->hParser->sembol[j],
                                         this->hParser->ad[j],
                                         this->hParser->fiyat[j],
                                         strlen(this->hParser->id[j]),
                                         strlen(this->hParser->sembol[j]),
                                         strlen(this->hParser->ad[j]));

        j++;
    }

    j = 2;
    for (i = 0; i < PortfoySayisi(); i++)
    {
        this->portfoyler[i] = PortfoyOlustur(this->pParser->id[j],
                                             this->pParser->sembol[j],
                                             this->pParser->maliyet[j],
                                             this->pParser->adet[j],
                                             strlen(this->pParser->id[j]),
                                             strlen(this->pParser->sembol[j]));
        j++;
    }
    EmirParserYoket(this->eParser);
    HisseParserYoket(this->hParser);
    PortfoyParserYoket(this->pParser);
    return this;
}
int portfoyBul(char semboller[], Banka banka)
{
    int i, j;
    int bulucu = 0;
    for (i = 0; i < PortfoySayisi(); i++)
    {

        for (j = 0; j < banka->portfoyler[i]->sembolSize; j++)
        {
            if (semboller[j] >= 'A' && semboller[j] <= 'Z' && banka->hisseler[i]->sembol[j] >= 'A' && banka->hisseler[i]->sembol[j] <= 'Z')
            {
                if (banka->portfoyler[i]->sembol[j] == semboller[j])
                {
                    bulucu = 1;
                }
                else
                {
                    bulucu = 0;
                    break;
                }
            }
            else{
                break;
            }
        }
        if (bulucu == 1)
        {

            return i;
        }
    }
    return 0;
}
int hisseBul(char semboller[], Banka banka)
{
    int i, j;
    int bulucu = 0;
    for (i = 0; i < HisseSayisi(); i++)
    {

        for (j = 0; j < banka->hisseler[i]->sembolSize; j++)
        {
            if (semboller[j] >= 'A' && semboller[j] <= 'Z' && banka->hisseler[i]->sembol[j] >= 'A' && banka->hisseler[i]->sembol[j] <= 'Z')
            {
                if (banka->hisseler[i]->sembol[j] == semboller[j])
                {

                    bulucu = 1;
                }
                else
                {
                    bulucu = 0;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (bulucu == 1)
        {

            return i;
        }
    }
    return 0;
}

void KarZararHesap(Banka banka)
{
    int i, j;
    int bulucu = 0;
    int prtfy, hss;
    double toplam = 0;
    printf("Satislar Kar/Zarar: \n");
    for (i = 0; i < EmirSayisi(); i++)
    {

        if (banka->emirler[i]->islem[0] == 'S' || banka->emirler[i]->islem[0] == 's')
        {
            prtfy = portfoyBul(banka->emirler[i]->sembol, banka);
            hss = hisseBul(banka->emirler[i]->sembol, banka);
            double guncelFiyat = banka->hisseler[hss]->fiyat * banka->portfoyler[prtfy]->adet;
            double maliyet = banka->portfoyler[prtfy]->maliyet * banka->portfoyler[prtfy]->adet;

            banka->portfoyler[prtfy]->adet = banka->portfoyler[prtfy]->adet - banka->emirler[i]->adet;

            if (guncelFiyat >= maliyet)
            {
                for (j = 0; j < banka->emirler[i]->sembolSize; j++)
                {
                    if (banka->emirler[i]->sembol[j] >= 'A' && banka->emirler[i]->sembol[j] <= 'Z')
                        printf("%c", banka->emirler[i]->sembol[j]);
                }
                printf(" :");
                printf("%lf", guncelFiyat - maliyet);
                printf(" TL Kar\n");
                toplam += (guncelFiyat - maliyet);
            }
            if (guncelFiyat < maliyet)
            {
                for (j = 0; j < banka->emirler[i]->sembolSize; j++)
                {
                    if (banka->emirler[i]->sembol[j] >= 'A' && banka->emirler[i]->sembol[j] <= 'Z')
                        printf("%c", banka->emirler[i]->sembol[j]);
                }
                printf(" :");
                printf("%lf", maliyet - guncelFiyat);
                printf(" TL Zarar\n");
                toplam += (guncelFiyat - maliyet);
            }
        }
    }
    printf("Toplam Kar/Zarar: ");
    if (toplam > 0)
        printf("+");
    printf("%lf", toplam);
    printf(" TL\n");
    printf("\n");
    printf("Guncel Portfoy:");
    printf("\n");
    for (i = 0; i < EmirSayisi(); i++)
    {

        if (banka->emirler[i]->islem[0] == 'A' || banka->emirler[i]->islem[0] == 'a')
        {
            prtfy = portfoyBul(banka->emirler[i]->sembol, banka);
            hss = hisseBul(banka->emirler[i]->sembol, banka);
            banka->portfoyler[prtfy]->maliyet = ((banka->portfoyler[prtfy]->maliyet * banka->portfoyler[prtfy]->adet) + (banka->emirler[i]->adet * banka->hisseler[hss]->fiyat)) / (banka->emirler[i]->adet + banka->portfoyler[prtfy]->adet);
            banka->portfoyler[prtfy]->adet += banka->emirler[i]->adet;
            int bulucu = 0;
            for (j = 0; j < banka->hisseler[hss]->sembolSize; j++)
            {
                if (banka->hisseler[hss]->sembol[j] == banka->portfoyler[prtfy]->sembol[j])
                {

                    bulucu = 1;
                }
                else
                {
                    bulucu = 0;
                    break;
                }
            }
            if (bulucu == 0)
            {
                printf("Hisse:");
                for (j = 0; j < banka->emirler[i]->sembolSize; j++)
                {
                    if (banka->emirler[i]->sembol[j] >= 'A' && banka->emirler[i]->sembol[j] <= 'Z')
                        printf("%c", banka->emirler[i]->sembol[j]);
                }
                printf("\n");
                printf("Adet:");
                printf("%d\n", banka->emirler[i]->adet);
                printf("Maliyet:");
                printf("%lf\n", banka->hisseler[hss]->fiyat);
                printf("-----------\n");
            }
        }
    }
    int z;
    for (z = 0; z < PortfoySayisi(); z++)
    {
        if (banka->portfoyler[z]->adet > 0)
        {
            printf("Hisse:");
            for (j = 0; j < banka->portfoyler[z]->sembolSize; j++)
            {
                if (banka->portfoyler[z]->sembol[j] >= 'A' && banka->portfoyler[z]->sembol[j] <= 'Z')
                    printf("%c", banka->portfoyler[z]->sembol[j]);
            }
            printf("\n");
            printf("Adet:");
            printf("%d\n", banka->portfoyler[z]->adet);
            printf("Maliyet:");
            printf("%lf\n", banka->portfoyler[z]->maliyet);
            printf("-----------\n");
        }
    }
}

void BankaYoket(const Banka this)
{
    if (this == NULL)
        return;
    free(this->emirler);
    free(this->hisseler);
    free(this->portfoyler);
    free(this);
}
