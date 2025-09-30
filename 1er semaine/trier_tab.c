#include<stdio.h>
#include<stdio.h>
#define taille 200


int main()
{
    int tab[taille], n, i_min, temp; 

    do{

        printf("entrer le nombre des element du tableaux, max 200:");
        scanf("%d",&n);
    
    }while(n<2 || n>taille);

    for(int i=0; i<n; i++)
    {

        printf("entrer tab[%d] \n", i);
        scanf("%d",tab+i);

    }

    for(int i=0; i<n-1; i++)
    {
        i_min=i;
        for(int j=i+1; j<n; j++)
        {
            if(tab[i_min]>tab[j])
                i_min=j;
        }

        temp = tab[i];
        tab[i] = tab[i_min];
        tab[i_min] = temp;

    }

    for(int i=0; i<n; i++)
    {

        printf("tab[%d]= %d\n", i, tab[i]);

    }
    return 0;
}