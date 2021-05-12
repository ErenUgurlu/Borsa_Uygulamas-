#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "../include/EmirParser.h"

EmirParser EmirParserOlustur()
{
    EmirParser this;

    this = (EmirParser)malloc(sizeof(struct EMIRPARSER));
    int emirSayisi = EmirSayisi() + 10;
    this->eParserYoket = &EmirParserYoket;
    this->id = (char **)malloc(sizeof(char *) * emirSayisi);
    this->sembol = (char **)malloc(sizeof(char *) * emirSayisi);
    this->islem = (char **)malloc(sizeof(char *) * emirSayisi);
    this->adet = (int *)malloc(sizeof(int) * emirSayisi);
    int x;
    for (x = 0; x < emirSayisi; x++)
    {
        this->id[x] = (char *)malloc(sizeof(char *) * 100);
        this->sembol[x] = (char *)malloc(sizeof(char *) * 100);
        this->islem[x] = (char *)malloc(sizeof(char *) * 100);
    }
    FILE *file;
    file = fopen("./doc/emirler.json", "r");
    if (file == NULL)
    {
        printf("emirler.json dosyasi acilamadi (emirparser dosyasında)");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }
    int noktaSayac = 0;
    int satir = 0;
    int key = 0;
    int virgul = 0;
    int tekint = 0;
    int i = 0;
    char iter;
    int iterNum;

    while (!feof(file))
    {

        fscanf(file, "%c", &iter);

        if (iter == ':')
        {
            noktaSayac++;
            tekint = 0;
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
                this->islem[satir][i] = iter;
                i++;
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

void EmirParserYoket(const EmirParser this)
{
    int x;
    if (this == NULL)
        return;
    for (x = 0; x < EmirSayisi() + 10; x++)
    {
        free(this->id[x]);
        free(this->sembol[x]);
        free(this->islem[x]);
    }
    free(this->id);
    free(this->sembol);
    free(this->islem);
    free(this->adet);
    free(this);
}