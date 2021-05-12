#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "../include/SatirSayici.h"

int HisseSayisi()
{
    int satir = 0;
    char iter;
    FILE *file;
    file = fopen("./doc/hisseler.json", "r");
    if (file == NULL)
    {
        printf("hisseler.json dosyasi acilamadi");
        exit(1);
    }

    while (!feof(file))
    {
        fscanf(file, "%c", &iter);
        if (iter == '{')
        {
            satir++;
        }
    }
    fclose(file);
    return satir;
}
int EmirSayisi()
{
    int satir = 0;
    char iter;
    FILE *file;
    file = fopen("./doc/emirler.json", "r");
    if (file == NULL)
    {
        printf("emirler.json dosyasi acilamadi");
        exit(1);
    }
    while (!feof(file))
    {
        fscanf(file, "%c", &iter);
        if (iter == '{')
        {
            satir++;
        }
    }
    fclose(file);
    return satir;
}
int PortfoySayisi()
{
    int satir = 0;
    char iter;
    FILE *file;
    file = fopen("./doc/portfoy.json", "r");
    if (file == NULL)
    {
        printf("portfoy.json dosyasi acilamadi");
        exit(1);
    }
    while (!feof(file))
    {
        fscanf(file, "%c", &iter);
        if (iter == '{')
        {
            satir++;
        }
    }
    fclose(file);
    return satir;
}