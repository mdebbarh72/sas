/*
Challenge 3 : Somme des N Nombres

Écrivez un programme C qui demande un nombre entier n à l’utilisateur 
et calcule la somme des n premiers nombres naturels.
 Par exemple, pour n = 4, la somme est 1 + 2 + 3 + 4 = 10.
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{

    int n, somme=0;
     
    do{

        printf("enter un entier n:");
        scanf("%d", &n);

    }while(n<1);

    for(int i=1; i<=n; i++)
    {
        somme+= i;
    }
     printf("la somme de %d premier nombre naturels est: %d", n, somme);
    
    return 0;
}