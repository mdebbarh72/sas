#include<stdio.h>
#include<stdlib.h>


int main()
{ 
    int n=5, i ,j ,k;

    for(i=1; i<n; i++)
    {
      for(k=0; k<n-i; k++)
      {
        printf(" ");
      }
      for(j=0; j<i*2-1; j++)
      {
        printf("*");
      }
      printf("\n");
    }
    


    return 0;
}