#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#define max_joueurs 100
#define taille 50

typedef struct{

    int jour;
    int mois;
    int anne;

}date;

typedef struct{

    int id;
    char nom[taille];
    char prenom[taille];
    int maillot;
    char poste[10];
    int age ;
    int buts;
    date date_inscription;
    char statut[15];

}joueur;


char positions[4][10]={ "gardien", "defenseur", "milieu", "attaquant"};
char statuts[2][15]={ "titulaire", "remplacant"};
int nb_joueurs=10;
int id_generateur=10;

joueur joueurs[max_joueurs] = {

    {0,"leonel", "messi", 10, "attaquant", 38, 800,{ 18, 12, 2022}, "titulaire"},
    {1, "neymar", "jr", 11, "attaquant", 30, 400, { 31, 7, 2023}, "titulaire"},
    {2, "louis", "suarez", 9, "attaquant", 37, 600, { 3, 7, 2021},"titulaire"},
    {3, "lamine", "yamal", 19, "attaquant", 18, 30, { 30, 6, 2024}, "titulaire"},
    {4, "pedri", "gonsalez", 8, "milieu", 22, 30, { 11, 7, 2021}, "titulaire"},
    {5, "ferenkie", "de jong", 21, "milieu", 28, 35, { 25, 7, 2019}, "titulaire"},
    {6, "alejandro", "balde", 3,"defenseur", 20, 11, { 28, 7, 2022}, "titulaire"},
    {7, "ronald", "aroujo", 4, "defenseur", 24, 8, { 3, 8, 2020}, "titulaire"},
    {8, "pau", "cubarsi", 5, "defenseur", 18, 4, { 12, 7, 2024}, "titulaire"},
    {9, "joules", "kounde", 23, "defenseur", 26, 10, { 20, 7, 2022}, "titulaire"},
    {10, "joan", "garcia", 1, "gardien", 23, 0, { 18, 7, 2025}, "titulaire"},

    };

void ajouter();
joueur remplir_joueur(int);
int rechercher_maillot(int);
int test_nom(char[]);


int menu()
{
    system("clear");
    int choix;
    while(getchar()!='\n');

    do
    {
        printf("menu:\n");
        printf("\t1- Ajouter un joueur.\n");
        printf("\t2- Afficher tout les joueurs.\n");
        printf("\t3- Modifier un joueur.\n");
        printf("\t4- Supprimer un joueur.\n");
        printf("\t5- Rechercher un joueur.\n");
        printf("\t6- Afficher des statistiques.\n");
        printf("\t0- Quitter le program.\n");

        printf("Votre choix est:");
        scanf("%d", &choix);

        if(choix < 0 || choix >6)
            printf("choix invalide!\n");
    }while(choix < 0 || choix >6);

}

int main()
{
    

    int quitter=1;

    do{
        switch(menu())
    {
        case 1: ajouter();


    }

    }while(quitter);
    

    

    





    return 0;
}

void ajouter()
{
    if( nb_joueurs==max_joueurs)
    {
        printf("impossile d\'ajouter un joueur, vous avez atteint le nombre maximum de joueurs autorises.\n");
        return;
    }

    int n, choix;

    printf("entrer le nombre de joueurs que tu veux ajouter, max 100:\n");
    scanf("%d", &n);

    if(n<1 || n > max_joueurs)
    {
        printf("nombre invalide!\n");
        return ajouter();
    }

    if(n+nb_joueurs> max_joueurs)
    {
        printf("impossile d\'ajouter %d joueurs, Il ne reste que %d places libres dans l\'equipe.\n", n, max_joueurs-nb_joueurs);

        do
        {
            printf("1- Changer le nombre qui tu veux ajouter.\n");
            printf("0- Quitter l\'operation.\n");
            scanf("%d", &choix);

            if(choix != 1 && choix != 0)
                printf("choix invalide!\n");

        } while (choix != 1 && choix != 0);

        if(choix)
            return ajouter();
        else
            return ;
    }
    
    for(int i=0; i<n; i++)
    {
        joueurs[i] = remplir_joueur(i);
    }

}

joueur remplir_joueur(int i)
{
    joueur j;

    do{
        printf("entrer le nom du joueur %d: ",i );
        fgets(j.nom, taille, stdin);
        j.nom[strcspn(j.nom, "\n")]= '\0';
    }while(test_nom(j.nom));

    do{
        printf("entrer le nom du joueur %d: ",i );
        fgets(j.prenom, taille, stdin);
        j.prenom[strcspn(j.prenom, "\n")]= '\0';
    }while(test_nom(j.prenom));

    do{
        printf("entrer le nom du joueur %d: ",i );
        scanf("%d", j.maillot);
    }while(rechercher_maillot(j.maillot)>=0);


    
}

int test_nom(char nom[])
{

}

int rechercher_maillot(int maillot)
{

    
}