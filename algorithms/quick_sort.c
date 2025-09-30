#include<stdio.h>
#include<stdlib.h>
#define max 100

void quicksort(int [], int, int);

int main()
{
    int t[max],n;


    do{
        printf("entrer le nombre des elements: ");
        scanf("%d",&n);
    }while(n<2 || n>max);

    printf("remplire le tableau\n");

    for(int i =0; i<n; i++)
    {
        printf("entrer la valeur %d: ", i+1);
        scanf("%d",t+i);
    }

    printf("----------avant-----------\n");

    for(int i =0; i<n; i++)
    {
        printf("t[%d]: %d\n", i, t[i]);
    }

    quicksort(t,0,n-1);

    printf("----------apres-----------\n");

    for(int i =0; i<n; i++)
    {
        printf("t[%d]: %d\n", i, t[i]);
    }


    return 0;
}


void quicksort(int t[], int start, int end)
{
    if(start<end)
    {
        int i= start-1; int temp;
        for(int j=start; j<end; j++)
        {
            if(t[j]<t[end])
            {
                i++;
                temp=t[i];
                t[i]=t[j];
                t[j]=temp;
            }
        }

        temp=t[end];
        t[end]= t[i+1];
        t[i+1]= temp;

        quicksort(t, start, i);
        quicksort(t, i+2, end);

    }

}

