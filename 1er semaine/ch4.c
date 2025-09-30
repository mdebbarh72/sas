/*Challenge 4 : Affichage des N Premiers Nombres Impairs

Écrivez un programme C qui demande un nombre entier n
 et affiche les n premiers nombres impairs.
  Par exemple, pour n = 5, affichez : 1, 3, 5, 7, 9.

*/
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i=1, cmp=0;
    
    do{
        printf("entrer le nombre des impaires:");
        scanf("%d",&n);

    }while(n<1);

    do{
        if(i%2 != 0)
    {
        printf("%d\t", i);
        cmp++;
    }
    i++;  
    }while(cmp<n);
        
    
    return 0;
}
