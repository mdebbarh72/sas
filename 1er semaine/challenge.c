/*
Challenge 1 : Définition et Utilisation de Structure
Écrivez un programme C qui définit une structure pour représenter une personne
avec les champs nom, prenom, et age.
Créez une variable de cette structure,
assignez des valeurs aux champs,
et affichez ces valeurs.
Challenge 2 : Structure avec Tableau
Écrivez un programme C qui définit une structure pour représenter un étudiant
 avec les champs nom, prenom, et un tableau d'entiers pour stocker les notes.
  Assignez des valeurs aux champs et aux notes,
 puis affichez les informations de l'étudiant.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define taille 50

typedef struct {
    char nom[taille];
    char prenom[taille];
    float notes[5];
}etudiants;


etudiants remplir();
void afficher(etudiants);

int main()
{
    etudiants e;

    e=remplir();
    afficher(e);

    return 0;
}

etudiants remplir()
{
    etudiants e;
    

    printf("entrer le nom de l\'etudiant:");
    fgets(e.nom, taille, stdin);
    e.nom[strcspn(e.nom,"\n")]='\0';

    printf("entrer le prenom de l\'etudiant:");
    fgets(e.prenom, taille, stdin);
    e.prenom[strcspn(e.prenom,"\n")]='\0';

    for(int i=0; i<5; i++)
    {
        do
        {
            printf("entrer la note %d: ", i+1);
            scanf("%f", &e.notes[i]);
        }while(e.notes[i]<0 || e.notes[i]>20);
    }

    return e;
}

void afficher( etudiants e)
{
    printf("le nom: %s\n", e.nom);
    printf("le nom: %s\n", e.prenom);

    for(int i=0; i<5; i++)
    {
        printf("note %d: %.2f\n", i+1, e.notes[i]);
    }

}
