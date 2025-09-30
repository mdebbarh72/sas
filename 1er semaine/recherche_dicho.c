#include<stdio.h>
#include<stdlib.h>

#define taille 200

int main ()
{
    int tab[taille], n,x, m, i, j, temp, i_min,test=0;

    do{
        printf("entrer le nombre des element du tableau, max 200:");
        scanf("%d",&n);
    }while(n<1 || n>200);


    for( i=0;i<n; i++)
    {
        printf("enter une valeur:");
        scanf("%d",&tab[i]);

    }

    
    for( i=0; i<n; i++)
    {

        printf("tab[%d]= %d\n", i, tab[i]);

    }
    for( i=0; i<n-1; i++)
    {
        i_min=i;
        for( j=i+1; j<n; j++)
        {
            if(tab[i_min]>tab[j])
                i_min=j;
        }

        temp = tab[i];
        tab[i] = tab[i_min];
        tab[i_min] = temp;

    }

    for( i=0; i<n; i++)
    {

        printf("tab[%d]= %d\n", i, tab[i]);

    }

    printf("entrer le nombre a chercher:");
    scanf("%d",&x);

    i=0;j=n-1;
    do{
        m=(i+j)/2;
        if(tab[m]==x)
        {
            test=1;
            break;
        }
            
        else if(tab[m]>x)
            j=m-1;
        else 
            i=m+1;


    }while(i<=j);

    if(test)
        printf("existe");
    else
        printf("n\'est pas existe");

    return 0;
}