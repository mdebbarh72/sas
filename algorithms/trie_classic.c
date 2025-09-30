#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#define taille 100

void tri_selection(int [], int);
void tri_bulles(int [], int);
void tri_insersion(int [], int);

int main(void)
{
    int T[taille],n,i,choix;
    
    do{
        printf("entrer le nombre d'éléments ≤100 : ");
        scanf("%d",&n);
    }while(n<1 || n>100);
    
    for(i=0; i<n; i++)
    {
        printf("entrer l'éléments %d: ",i+1);
        scanf("%d",&T[i]);
    }
    
    do{
        printf("choisir une trie: ");
        printf("\n    1-trie par selection.");
        printf("\n    2-trie bulles.");
        printf("\n    3-trie par insersion.");
        printf("\nvotre choix est: ");
        scanf("%d",&choix);
    }while(choix<1 || choix >3);
    
    switch(choix)
    {
        case 1: printf("le tableau avant le trie:\n");
                for(i=0; i<n; i++)
                    printf("%d\n",T[i]);
                    
                tri_selection(T,n);
                
                printf("le tableau après le trie:\n");
                for(i=0; i<n; i++)
                    printf("%d\n",T[i]);
                break;
        case 2: printf("le tableau avant le trie:\n");
                for(i=0; i<n; i++)
                    printf("%d\n",T[i]);
                    
                tri_bulles(T,n);
                
                printf("le tableau après le trie:\n");
                for(i=0; i<n; i++)
                    printf("%d\n",T[i]);
                break;
        case 3: printf("le tableau avant le trie:\n");
                for(i=0; i<n; i++)
                    printf("%d\n",T[i]);
                    
                tri_insersion(T,n);
                
                printf("le tableau après le trie:\n");
                for(i=0; i<n; i++)
                    printf("%d\n",T[i]);
                break;
    }
    return 0;
}

void tri_selection(int tab[], int N)
{
    int i, j, i_min,temp;
    for(i=0; i<N-1; i++)
    {
        i_min=i;
        for(j=i+1; j<N; j++)
        {
            if(tab[j]<tab[i_min])
                i_min=j;
        }
        temp=tab[i_min];
        tab[i_min]=tab[i];
        tab[i]=temp;
    }
}

void tri_bulles(int tab[], int N)
{
    int temp,x=N; 
    bool inversion=true;
    for(int i=0; i<N; i++)
    {   inversion=false;
        for(int j=0; j<x-1; j++)
        {   
            if(tab[j+1]<tab[j])
            {
                temp=tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
                inversion=true;
            }
        }
        if(!inversion)
            break;
        x--;
    }    
}

void tri_insersion(int tab[], int N)
{
    int j,temp;
    for(int i=0; i<N; i++)
    {
        j=i-1;
        while(j>=0 && tab[j]>tab[j+1])
        {
            temp=tab[j];
            tab[j]=tab[j+1];
            tab[j+1]=temp;
            j--;
        }
    }
}