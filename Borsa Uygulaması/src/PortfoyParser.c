#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "../include/PortfoyParser.h"



PortfoyParser PortfoyParserOlustur()
{
    
    PortfoyParser this;
    this = (PortfoyParser)malloc(sizeof(struct PORTFOYPARSER));
    int portfoySayisi = PortfoySayisi()+ 10;

    this->id = (char **)malloc(sizeof(char *) * portfoySayisi);
    this->sembol = (char **)malloc(sizeof(char *) * portfoySayisi);
    this->maliyet = (double *)malloc(sizeof(double) * portfoySayisi);
    this->adet = (int *)malloc(sizeof(int) * portfoySayisi);
    int x;
    for (x = 0; x < portfoySayisi; x++)
    {
        this->id[x] = (char *)malloc(sizeof(char *) * 100);
        this->sembol[x] = (char *)malloc(sizeof(char *) * 100);
    }
    

    FILE *file;
    file = fopen("./doc/portfoy.json", "r");
    if (file == NULL)
    {
        printf("Portfoy.json dosyasi acilamadı (portfoyparser.c nin icindeki)");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    int noktaSayac = 0;
    int satir = 0;
    int key = 0;
    int virgul = 0;
    int tekint = 0;
    int tekdouble = 0;
    int i = 0;
    char iter;
    int iterNum;
    double iterDouble;

    while (!feof(file))
    {

        fscanf(file, "%c", &iter);

        if (iter == ':')
        {
            noktaSayac++;
            tekint = 0;
            tekdouble =0;
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
            if (virgul == 0)
            {
                if (tekdouble == 0)
                {
                    fscanf(file, "%lf", &iterDouble);
                   this-> maliyet[satir] = iterDouble;
                }

                tekdouble++;
            }
        }
        if (noktaSayac == 5)
        {
            if (virgul == 0)
            {

                if (tekint == 0)
                {
                    fscanf(file, "%d", &iterNum);
                    this->adet[satir] = iterNum;
                }

                tekint++;
            }
        }
    }

    fclose(file);

    return this;
}

void PortfoyParserYoket(const PortfoyParser this)
{
    int x;
    if (this == NULL)
        return;
    for (x = 0; x < PortfoySayisi() + 10; x++)
    {
        free(this->id[x]);
        free(this->sembol[x]);
    }
    free(this->id);
    free(this->sembol);
    free(this->maliyet);
    free(this->adet);
    free(this);
}