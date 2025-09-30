#include<stdio.h>
#include<stdlib.h>
#define taille 100

void initialisation(int [], int);
void affichage(int tab[], int );
int somme(int[], int);
long produit(int[], int);
void max_min( int [], int);
void trier(int tab[], int n);
void copie(int[],int[], int);
void inverser(int[], int);
int rechercher(int[], int, int);
void remplacer(int[], int);
void pair(int [], int );
void impair(int [], int );
double moyen(int [], int );
int* fusionner(int *, int*, int , int );






int main()
{
    int tab[taille], n, tab2[taille],choix ;
    
    do{

        printf("entrer le nombre des element du tableaux, max 200:");
        scanf("%d",&n);
    
    }while(n<2 || n>taille);

    initialisation(tab,n);
    affichage(tab,n);

    do{
        printf("voici le menu:\n");
    printf("\t1- somme des element du tableau.\n");
    printf("\t2- afficher le max et le min du tableau.\n");
    printf("\t3- produit des element du tableau.\n");
    printf("\t4- trier le tableau .\n");
    printf("\t5- copier les element dans un autre tableau.\n");
    printf("\t6- cherhcer un element dans le tableau.\n");
    printf("\t7- remplacer un element tableau.\n");
    printf("\t8- afficher les nombre pair.\n");
    printf("\t9- afficher les nombre impair.\n");
    printf("\t10- calculer le moyen.\n");
    printf("\t11- fusionner deux tableaux.\n");
    printf("votre choix est:");
    scanf("%d", &choix);
    }while(choix<1 || choix >11);

    switch(choix)
    {
        case 1: printf("la somme est:%d",somme(tab,n));
                break;
        case 2: max_min(tab, n);break;
        case 3: printf("le produit est: %ld", produit(tab,n)); break;
        case 4: trier(tab,n); break;
        case 5: copie(tab, tab2, n); break;
        case 6: int x;
                printf("entrer un nombre a chercher:");
                scanf("%d",&x);
                if(rechercher(tab, n, x))
                    printf("%d existe dans le tableau.",x);
                else 
                    printf("%d n\'existe pas.",x);
                break;
        case 7: remplacer(tab, n); break;
        case 8: pair(tab, n); break;
        case 9: impair(tab, n); break;
        case 10: printf("le moyen est: %lf", moyen(tab, n)); break;
        case 11: int *f,m;
                 do{

                    printf("entrer le nombre des element du tableaux, max 200:");
                    scanf("%d",&m);
    
                    }while(m<2 || m>taille);
                 initialisation(tab2,m);
                 f=fusionner(tab, tab2, n, m);
                 affichage(f, n+m);
                 free(f);
                 break;
    }
    printf("\n mercie pour utuliser le programme");
    
    return 0;
}

void initialisation(int tab[], int n)
{
    //initialisation
    printf("entrer les valeur du tablau:\n");
    for(int i=0; i<n; i++)
    {
        printf("entrer tab[%d]:", i);
        scanf("%d", &tab[i]);
    }

}
void affichage(int tab[], int n)
{    //affichage
    printf("voici les valeur du tablau:\n");
    for(int i=0; i<n; i++)
    {
        printf("tab[%d]= %d\n", i,tab[i]);
    }
}
int somme(int tab[], int n)
{
    int somme=0;

    for(int i=0; i<n; i++)
    {
        somme+= tab[i];
    }
    return somme;
}

void max_min( int tab[], int n)
{
    int max, min;
    max=min=tab[0];

    for(int i=1; i<n; i++)
    {
        if(tab[i]<min)
            min= tab[i];
        if(tab[i]>max)
            max=tab[i];

    }

    printf("les maximum du tableau est: %d.\n",max);
    printf("les minimum du tableau est: %d.", min);

}

long produit(int tab[], int n)
{
    long pr=1;

    for(int i=0; i<n; i++)
    {
        pr*= tab[i];
    }
    return pr;
}

void trier(int tab[], int n)
{
    int i_min, temp;

    printf("avant le trie.");
    affichage(tab, n);

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

    printf("apres le trie.");
    affichage(tab, n);
}

void copie(int tab[], int tab2[], int n)
{
    for(int i=0; i<n; i++)
    {
        tab2[i]= tab[i];
    }
    printf("le tableau a ete copie:\n");
    affichage(tab2, n);
}

void inverser(int tab[], int n)
{
    int temp,m= n/2;

    for(int i=0; i<m; i++)
    {
        temp=tab[i];
        tab[i]= tab[n-1-i];
        tab[n-1-i]= temp;
    }

    printf("le tableau a ete inverser.\n");

    affichage(tab,n);
}

int rechercher(int tab[], int n, int x)
{

    for(int i=0; i<n; i++)
    {
        if(tab[i]==x)
            return 1;
    }

    return 0;
    
}

void remplacer(int tab[], int n )
{
    int x, y;
    do{
        printf("entrer le nombre a remplacer:");
        scanf("%d",&x);
       
    }while(!rechercher(tab, n, x));

    printf("entrer le nouvel nombre:");
    scanf("%d", &y);

    for(int i=0; i<n; i++)
    {
        if(tab[i]==x)
        {
            tab[i]=y;
            break;
        }
    }

    printf("le nombre a ete remplacer.");
    affichage(tab, n);
}

void pair(int tab[], int n)
{
    printf("voici les nombre pair:");
    for(int i=0; i<n; i++)
    {
        if(tab[i]%2==0)
            printf("%d\t", tab[i]);
    }
}

void impair(int tab[], int n)
{
    printf("voici les nombre impair:");
    for(int i=0; i<n; i++)
    {
        if(tab[i]%2!=0)
            printf("%d\t", tab[i]);
    }
}

double moyen(int tab[], int n)
{
    int s;
    s= somme(tab,n);
    return s/(double)n;
}

int* fusionner(int *t1, int* t2, int n, int m)
{
    int *f, i, j;
    
    f=(int*)malloc((n+m)*sizeof(int));

    for(i=0; i<n; i++)
    {
        *(f+i)= *(t1+i);
    }

    for(j=0; j<m; j++)
    {
        *(f+n+j)= *(t2+j);
    }
    
    return f;

}

