#include<stdio.h>
#include<stdlib.h>

#define taille 200

int main ()
{
    int *t1, *t2, *f, n, m, i;

    do{
        printf("entrer le nombre des element du tableau, max 200:");
        scanf("%d",&n);
    }while(n<1 || n>taille);

    t1=(int*)malloc(n*sizeof(int));

    do{
        printf("entrer le nombre des element du tableau, max 200:");
        scanf("%d",&m);
    }while(m<1 || m>200);

     t2=(int*)malloc(m*sizeof(int));


    printf("enter les valeur du t1\n");
    for( i=0;i<n; i++)
    {
        printf("enter une valeur:");
        scanf("%d",t1+i);

    }

    printf("enter les valeur du t2\n");
    for( i=0;i<n; i++)
    {
        printf("enter une valeur:");
        scanf("%d",t2+i);

    }

    f=(int*)malloc((n+m)*sizeof(int));

    for(i=0; i<n; i++)
    {
        *(f+i)=*(t1+i);
    }
    for(int j=0; j<m; j++)
    {
        *(f+i+j)=*(t2+j);
    }

    printf("voici le tableau fusioner:\n");

    for(i=0; i<n+m; i++)
    {
        printf("tab[%i]= %d\n",i,*(f+i));
    }


    return 0;
}
