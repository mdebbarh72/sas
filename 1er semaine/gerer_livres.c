#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define YEL "\e[0;33m"
#define WHT "\e[0;37m"
#define BLU "\e[0;34m"
#define URED "\e[4;31m"
#define stockage 200
#define taille 50

void ajouter(char[][taille], char[][taille], float[], int[], int*);
void afficher(char[][taille], char[][taille], float[], int[], int*);
int rechercher(char[][taille], char[][taille], int*);
void modifier_quantite(char[][taille], char[][taille], int[], int*);
void supprimer(char[][taille], char[][taille], float[], int[], int*);




int main()
{

    char titre[stockage][taille], auteur[stockage][taille], c;
    int quantite[stockage],stock=0,choix, quit=0;
    float prix[stockage];
    char quiter;

    do
    {
        do{
            printf("voici votre menu:\n");
            printf("\t 1-Ajouter un livre au stock.\n");
            printf("\t 2-Afficher tous les livres disponibles.\n");
            printf("\t 3-Rechercher un livre par son titre.\n");
            printf("\t 4-Mettre à jour la quantité d'un livre.\n");
            printf("\t 5-Supprimer un livre du stock.\n");
            printf("\t 6-Afficher le nombre total de livres en stock.\n");
            printf("\t 0-quiter le programme.\n");
            printf("votre choix est: ");
            scanf("%d",&choix);
        }while(choix<0 || choix>6);

        switch(choix)
        {
            case 1: ajouter(titre, auteur, prix, quantite, &stock);
                    break;
        
            case 2: afficher(titre, auteur, prix, quantite, &stock);
                    break;

            case 3: int existe;
                    existe = rechercher(titre, auteur, &stock);

                    if (existe== -1)
                        printf("le livre n'existe pas dans le stock!");
                    else
                    {
                        printf("titre: %s\n", titre[existe]);
                        printf("auteur: %s\n", auteur[existe]);
                        printf("titre: %.2f dh\n", prix[existe]);
                        printf("quantite: %d\n", quantite[existe]);
                    }
                    break;
                    
                case 4: modifier_quantite(titre, auteur, quantite, &stock);
                    break;
            
                case 5: int test;
                        do{
                            printf("confirmation du suppression:\n");
                            printf("\t1- pour supprimer un livre\n");
                            printf("\t0- pour retourner au menu\n");
                            printf("votre choix est:");
                            scanf("%d",&test);
                        }while(test !=0 && test != 1);
                        if(test)
                        {
                            supprimer(titre, auteur, prix, quantite, &stock);
                            break;
                        }
                        else
                            break;
                case 6: int totale=0;
                        for(int i=0; i<stock; i++)
                        {
                            totale+=quantite[i];
                        }
                        printf("le nobre totale de livres en stock est: %d", totale);
                        break;
                case 0: quit=1; break;
            }
        if(quit)
            break;
        else
        {
            do{
                while ((c = getchar()) != '\n' && c != EOF);
                printf("entrer q pour quiter ou r pour retourner au menu: " );
                scanf("%c",&quiter);
            }while(quiter!='r' && quiter!='R' && quiter!='q' && quiter!='Q');
        }
    
    }while(quiter=='r' || quiter== 'R' );

    return 0;
}
   



void ajouter(char titre[][taille], char auteur[][taille], float prix[], int quantite[], int* stock)
{
    if(*stock == stockage)
        printf("le stockage est plaine!");
    else 
    {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        printf("entrer le titre du livre: ");
        fgets(titre[*stock], taille, stdin);
        titre[*stock][strcspn(titre[*stock], "\n")] = '\0';
        printf("entrer l\'auteur du livre: ");
        fgets(auteur[*stock], taille, stdin);
        auteur[*stock][strcspn(auteur[*stock], "\n")] = '\0';
        printf("entrer le Prix du livre: ");
        scanf("%f",&prix[*stock]);
        printf("entrer la quantite en stock.: ");
        scanf("%d",&quantite[(*stock)++]);
    }

}

void afficher(char titre[][taille], char auteur[][taille], float prix[], int quantite[], int *stock)
{   
    printf("+----------+----------+--------+--------+""\n");
    printf("|  "  YEL "titre" WHT "   |  " YEL "auteur" WHT "  |  " YEL "prix" WHT "  |  " YEL "Qant" WHT "  |" "\n");
    printf("+----------+----------+--------+--------+" "\n");
    for(int i=0; i<*stock; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(j==0 || j%2==0)
                printf(WHT"|   ");
            else
            {
                switch(j)
                {
                    case 1: printf("%s  ",titre[i]); break;
                    case 3: printf("%s  ",auteur[i]); break;
                    case 5: printf("%.2f  ",prix[i]); break;
                    case 7: printf("%d  ",quantite[i]); break;
                }     
            }
        }
                    
        printf(WHT"|\n");
    }
    printf("+----------+----------+--------+--------+\n");
}

int rechercher(char titre[][taille], char auteur[][taille], int *stock)
{
    char title[taille], author[taille];

    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    printf("entrer le titre:");
    fgets(title, taille, stdin);
    printf("entrer l\'auteur:");
    fgets(author, taille, stdin);
                        
    for(int i=0; i<*stock; i++)
    {
        if(strcmpi(titre[i],title)==0 && strcmpi(auteur[i],author)==0 )
            return i;
    }
    return -1;
}

void modifier_quantite(char titre[][taille], char auteur[][taille], int quantite[], int* stock)
{
    if(*stock==0)
    printf("option non valide, car le stock est vide!");
    else
    {
    int existe;

    do{
        existe=rechercher(titre, auteur, stock);

        if(existe!=-1)
        {
            printf("entrer la nouvelle quantite:");
            scanf("%d", &quantite[existe]);
            printf("la quantite a ete modifier\n");
            return ;
        }
        else
        {
            printf("le livre n'existe pas dans le stock!\n");
            printf("entrer 1 pour reentrer un titre ou 0 pour retourner au menu: ");
            scanf("%d",&existe);
            if(!existe)
                return ;
        }
    }while(existe);

    }
}

void supprimer(char titre[][taille], char auteur[][taille], float prix[], int quantite[], int *stock)
{
    int test=0;
    char title[taille], author[taille],c;
    do
    {
        while ((c = getchar()) != '\n' && c != EOF);
        printf("entrer le titre:");
        fgets(title, taille, stdin);
        while ((c = getchar()) != '\n' && c != EOF);
        printf("entrer l\'auteur:");
        fgets(author, taille, stdin);

    for(int i=0; i<*stock; i++)
    {
        if(strcmpi(titre[i],title)==0 && strcmpi(auteur[i],author)==0 )
        {
            for(int j=i; j<(*stock)-1; j++)
            {
                strcpy(titre[j],titre[j+1]);
                strcpy(auteur[j],auteur[j+1]);
                prix[j]= prix[j+1];
                quantite[j]= quantite[j+1];
            }
            i--;
            (*stock)--;
            test=1;
        }
    }
    if(test)
        printf("le livre a ete supprime avec succe");
    else
    {
        printf("le livre n\'existe pas!");
        printf("entrer 1 pour supprimer un autre titre, ou 0 pour retourner au menu:");
        scanf("%d", &test);
    }
        
    }while(test);
    
}