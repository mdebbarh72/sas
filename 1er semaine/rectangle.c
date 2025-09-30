#include<stdio.h>
#include<stdlib.h>


typedef struct rectangle
{
    float  longeur;
    float largeur;
} rectangle;

float calculer_aire(rectangle);

int main()
{
    rectangle rec;
    float air;

    rec.largeur=13.5;
    rec.longeur=5.7;

    air=calculer_aire(rec);
    printf("l\'aire: %.2f",air);

    return 0;
}

float calculer_aire(rectangle R)
{
    float air;

    air= R.largeur*R.longeur;

    return air;
}
