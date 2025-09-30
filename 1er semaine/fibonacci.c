#include<stdio.h>
#include<stdlib.h>

int main()
{
    int u0=1,u1=1, Un=0, n, i=2;  
    

    do{
        printf("entrer un entier psitif:");
        scanf("%d", &n);
    }while(n<0);

    if(n==1 || n==2)
    {
        printf("Un= 1");
    }
    else
    {
        do{
            Un= u0+u1;
            u0= u1;
            u1=Un;
            i++;
        }while(i<=n);

    }

    printf("U%d= %d", n, Un);


    return 0;
}