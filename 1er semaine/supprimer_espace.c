#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{

    char ch[50], *p, *q;


    printf("entrer une chaine de charachter:");
    fgets(ch, 50, stdin);

    printf("la chaine avant la suppression des espace: \n");
    puts(ch);


    p=q=ch;
    for(; *p; p++ )
    {
        *q=*p;
        if(*q!= ' ')
            q++;
    }

    printf("la chaine apre la suppression des espaces: \n");
    puts(ch);

    return 0;
}