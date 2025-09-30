#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char chaine[100], sous_chaine[20], *p, *q, *r, *s;

    printf("entrer une chaine:");
    fgets(chaine, 100, stdin);
    printf("entrer une sous chaine:");
    fgets(sous_chaine, 20, stdin);
    sous_chaine[strcspn(sous_chaine, "\n")] = '\0';

    p=chaine; q=sous_chaine;
    int existe=0;
    for( ; *p; p++)
    {
        if(*p==*q)
        {
            existe=1;
            for(r=p, s=q; *s; r++, s++)
            {
                if(*r!=*s)
                {
                    existe=0;
                    break;
                }
            }
            if(existe)
                break;

        }
    }
    if(existe)
        printf("la sous chaine existe dans l\'indice %d.", p-chaine);
    else    
        printf("sous chaine n\'existe pas.");
    
    return 0;
}