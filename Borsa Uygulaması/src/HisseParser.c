#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "../include/HisseParser.h"

HisseParser HisseParserOlustur()
{

    HisseParser this;
    this = (HisseParser)malloc(sizeof(struct HISSEPARSER));
    int hisseSayisi = HisseSayisi() + 10;

    this->id = (char **)malloc(sizeof(char *) * hisseSayisi);
    this->sembol = (char **)malloc(sizeof(char *) * hisseSayisi);
    this->ad = (char **)malloc(sizeof(char *) * hisseSayisi);
    this->fiyat = (double *)malloc(sizeof(double) * hisseSayisi);
    int x;
    for (x = 0; x < hisseSayisi; x++)
    {
        this->id[x] = (char *)malloc(sizeof(char *) * 100);
        this->sembol[x] = (char *)malloc(sizeof(char *) * 100);
        this->ad[x] = (char *)malloc(sizeof(char *) * 100);
    }

    FILE *file;
    file = fopen("./doc/hisseler.json", "r");
    if (file == NULL)
    {
        printf("Hisseler.json dosyasi acilamadi(hisseparser dosyasinda)");
        exit(1);
    }

    int noktaSayac = 0;
    int satir = 0;
    int key = 0;
    int virgul = 0;
    double tekdouble = 0;
    int i = 0;
    char iter;
    double iterDouble;

    while (!feof(file))
    {

        fscanf(file, "%c", &iter);

        if (iter == ':')
        {
            noktaSayac++;
            tekdouble = 0;

            virgul = 0;
            i = 0;
        }
        if (iter == '{')
        {
            satir++;
            noktaSayac = 1;
        }
        if (iter == '"')
        {
            if (key == 1)
                key = 0;
            else
            {
                fscanf(file, "%c", &iter);
                key = 1;
            }
        }
        if (iter == ',' || iter == '}')
            virgul = 1;

        if (noktaSayac == 2)
        {
            if (key == 1 && virgul == 0)
            {
                this->id[satir][i] = iter;
                i++;
            }
        }
        if (noktaSayac == 3)
        {
            if (key == 1 && virgul == 0)
            {
                this->sembol[satir][i] = iter;
                i++;
            }
        }
        if (noktaSayac == 4)
        {
            if (key == 1 && virgul == 0)
            {
                this->ad[satir][i] = iter;
                i++;
            }
        }
        if (noktaSayac == 5)
        {
            if (virgul == 0)
            {
                if (tekdouble == 0)
                {
                    fscanf(file, "%lf", &iterDouble);
                    this->fiyat[satir] = iterDouble;
                }

                tekdouble++;
            }
        }
    }

    
    fclose(file);

    return this;
}

void HisseParserYoket(const HisseParser this)
{
    int x;
    if (this == NULL)
        return;
    for (x = 0; x < HisseSayisi() + 10; x++)
    {
        free(this->id[x]);
        free(this->sembol[x]);
        free(this->ad[x]);
    }
    free(this->id);
    free(this->sembol);
    free(this->ad);
    free(this->fiyat);
    free(this);
}


    