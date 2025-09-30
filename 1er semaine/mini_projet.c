#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define taille 30
#define taille_telephone 20
#define max 200
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

typedef struct 
{
    char nom[taille];
    char telephone[taille];
    char email[taille];
    int id;

}contact;

int enregistre=10;

void ajouter(contact [], int);
void afficher(contact []);
void rechercher(contact[]);
int rechercher_nom(contact[], char[]);
int rechercher_id(contact[], int);
void modifier(contact[]);
void supprimer(contact[]);

int main(void)
{
    contact contacts[max];

    strcpy(contacts[0].nom,"ahmed");
    strcpy(contacts[0].telephone,"0512345678");
    strcpy(contacts[0].email,"ahmed@gmail.com");
    contacts[0].id=1;

    strcpy(contacts[1].nom,"ayoub");
    strcpy(contacts[1].telephone,"0522345678");
    strcpy(contacts[1].email,"ayoub@gmail.com");
    contacts[1].id=2;

    strcpy(contacts[2].nom,"bouchaib");
    strcpy(contacts[2].telephone,"0532345678");
    strcpy(contacts[2].email,"bouchaib@gmail.com");
    contacts[2].id=3;

    strcpy(contacts[3].nom,"khaled");
    strcpy(contacts[3].telephone,"0542345678");
    strcpy(contacts[3].email,"ahmed@gmail.com");
    contacts[3].id=4;

    strcpy(contacts[4].nom,"said");
    strcpy(contacts[4].telephone,"0552345678");
    strcpy(contacts[4].email,"said@gmail.com");
    contacts[4].id=5;

    strcpy(contacts[5].nom,"ossama");
    strcpy(contacts[5].telephone,"0562345678");
    strcpy(contacts[5].email,"ossama@gmail.com");
    contacts[5].id=6;

    strcpy(contacts[6].nom,"zakaryiae");
    strcpy(contacts[6].telephone,"0572345678");
    strcpy(contacts[6].email,"zakaryiae@gmail.com");
    contacts[6].id=7;

    strcpy(contacts[7].nom,"yasser");
    strcpy(contacts[7].telephone,"0582345678");
    strcpy(contacts[7].email,"yasser@gmail.com");
    contacts[7].id=8;

    strcpy(contacts[8].nom,"mohammed");
    strcpy(contacts[8].telephone,"0588345678");
    strcpy(contacts[8].email,"mohammed@gmail.com");
    contacts[8].id=9;

    strcpy(contacts[9].nom,"saad");
    strcpy(contacts[9].telephone,"0582845678");
    strcpy(contacts[9].email,"saad@gmail.com");
    contacts[9].id=10;


    char quitter;
    int choix, choix_incalide=0;

    printf(MAG"===================Bienvenue==================\n");
    
    do
    {
        choix_incalide=0;
        quitter='r';
        choix=0;
        
        printf(BLU"  voici votre menu:\n");
        printf("\t1-Ajouter un Contact.\n");
        printf("\t2-Afficher tous les contactes.\n");
        printf("\t3-Modifier un Contact.\n");
        printf("\t4-Supprimer un Contact.\n");
        printf("\t5-Rechercher un Contact.\n");
        printf(MAG"votre choix est: ");
        scanf("%d",&choix);


        switch(choix)
        {
            case 1: int n;
                    if(enregistre==max)
                        printf(RED"impossible d\'ajouter un contact, vous avez deja enregistre le maximum nombre de contacs possible!\n");
                    
                    else
                    {
                        do
                        {
                            printf(MAG"entrer le nombre des contacts que tu veux ajouter: ");
                            scanf("%d", &n);
                        }while(n<0 || n>max);

                        ajouter(contacts,n);
                        
                    }
                    break;

            case 2: afficher(contacts); break;

            case 3: modifier(contacts); break;

            case 4: supprimer(contacts); break;

            case 5: rechercher(contacts); break;

            default: printf(RED"choix invalide!\n");
                     choix_incalide=1;  
                     break;         
        }

        if(choix_incalide)
            continue;
        else
        {
            do
            {
                printf(MAG"entrer r pour retourner au menu ou q pour quitter:");
                scanf("%c", &quitter);
            }while(quitter!='r' && quitter!='R' && quitter!= 'q' && quitter!='Q');
            
        }
        while(getchar()!='\n');
    }while(quitter=='r' || quitter=='R');


    return 0;
}

void ajouter(contact contacts[], int n)
{
    contact c;
    int existe;
    char *test_email;
    int test_telephone=0;

    if(enregistre+n>=max)
    {
        printf(RED"impossible d\'ajouter %d contacts, le nombre de contact disponible a ajoute est: %d\n", n, max-enregistre);
        return;
    }



    for(int i=0; i<n; i++)
    {
        do
        {
            while(getchar()!= '\n');
            printf(MAG"entrer le nom: ");
            fgets(c.nom, taille, stdin);
            c.nom[strcspn(c.nom,"\n")]='\0';
            existe=rechercher_nom(contacts, c.nom);
            
        }while(existe>=0);

        do{

            printf(MAG"entrer le telephone: ");
            fgets(c.telephone, taille_telephone, stdin);
            c.telephone[strcspn(c.telephone,"\n")]='\0';
            
            test_telephone=0;
            if(strlen(c.telephone)!=10)
                test_telephone=1;
            else
            {
                for(int i=0; i < strlen(c.telephone); i++)
                {
                    if(c.telephone[i]<'0' || c.telephone[i]>'9')
                    {
                        test_telephone=1;
                        break;
                    }
                }
            }
            
            if( test_telephone || c.telephone[0]!='0' || (c.telephone[1]!='5' && c.telephone[1]!='6' && c.telephone[1]!='7')  )
                printf(RED"format invalid!\n");
        }while(test_telephone || c.telephone[0]!='0' || (c.telephone[1]!='5' && c.telephone[1]!='6' && c.telephone[1]!='7') );
        
        do
        {
            printf(MAG"entrer l\'email: ");
            fgets(c.email, taille, stdin);
            c.email[strcspn(c.email,"\n")]='\0';
            test_email=strstr(c.email,"@gmail.com");

            if(test_email==NULL || *(test_email+10)!='\0')
                printf(RED"format invalide!\n");
        } while (test_email == NULL || *(test_email+10)!='\0');
        
        c.id= enregistre+1;
        contacts[enregistre++]=c;
        printf(GRN"contact ajoute avec succe\n");
    }
    
}

void afficher(contact contacts[])
{
    if(enregistre==0)
    {
        printf(RED"pas de contacts enregistre!\n");
        return;
    }
    printf(MAG"+---------------------------------------------------------------------------------------+\n");
    printf(BLU"|  id |              nom               |   telephone   |              email             | \n");
    printf(MAG"+---------------------------------------------------------------------------------------+\n");
    for(int i=0; i<enregistre; i++)
    {
        printf(BLU"| %-3d | %-30s | %-13s | %-30s |\n",contacts[i].id,contacts[i].nom,contacts[i].telephone,contacts[i].email);
    }
    printf(MAG"+---------------------------------------------------------------------------------------+\n");
}

void rechercher(contact contacts[])
{
    char nom[taille];
    int existe, choix, id;

    do{
        printf(MAG"entrer 1 pour rechercher par le nom, ou 2 pour rechercher par le id:");
        scanf("%d", &choix);

        if(choix==1)
        {
            while(getchar() != '\n');
            printf(MAG"entrer le nom a chercher: ");
            fgets(nom,taille,stdin);
            nom[strcspn(nom,"\n")]='\0';

            if((existe=rechercher_nom(contacts,nom))==-1)
                printf(RED"contact introuvable!\n");
            else
            {
                printf(MAG"+-----------------------------------------------+\n");
                printf(BLU"\t id \t  nom  \t    telephone    \t       email \n");
                printf(MAG"+------------------------------------------------+\n");
                printf(BLU"\t%d %s\t%s\t%s",contacts[existe].id,contacts[existe].nom,contacts[existe].telephone,contacts[existe].email);
                printf(MAG"+------------------------------------------------+\n");
            }
        }
        else if(choix == 2)
        {
            printf(MAG"entrer l\'id:");
            scanf("%d", id);
            if((existe=rechercher_id(contacts,id))==-1)
                printf(RED"contact introuvable!\n");
            else
            {
                printf(MAG"+---------------------------------------------------------------------------------------+\n");
                printf(BLU"|  id |              nom               |   telephone   |              email             | \n");
                printf(MAG"+---------------------------------------------------------------------------------------+\n");
                for(int i=0; i<enregistre; i++)
                {
                    printf(BLU"| %-3d | %-30s | %-13s | %-30s |\n",contacts[i].id,contacts[i].nom,contacts[i].telephone,contacts[i].email);
                }
                printf(MAG"+---------------------------------------------------------------------------------------+\n");
            }
        }
        else
            printf(RED "choix invalide!");

    }while(choix!=1 && choix !=2);
    
}

int rechercher_nom(contact contacts[], char nom[])
{ 
    for(int i=0; i<enregistre; i++)
    {
        if(strcmpi(contacts[i].nom, nom)==0)
            return i;
    }
    return -1;
}
int rechercher_id(contact contacts[], int id)
{
    for(int i=0; i<enregistre; i++)
    {
        if(id == contacts[i].id)
            return i;
    }
    return -1;
}

void modifier(contact contacts[])
{
    char nom[taille];
    int existe, choix, test_telephone;
    char* test_email;

    while(getchar()!='\n');
    do
    {
        printf(MAG"entrer le nom du contact a modifier:");
        fgets(nom,taille,stdin);
        nom[strcspn(nom,"\n")]='\0';

        if((existe=rechercher_nom(contacts, nom))==-1)
            printf(RED"contact introuvable!\n");

    }while(existe==-1);

    do
    {
        printf(MAG"entrer 1 pour confirmer, ou 0 pour annuler la modefication:");
        scanf("%d", &choix);

        if(!choix)
            return;
    }while(choix!=0 && choix!=1);

    do{
        getchar();
        printf(MAG"entrer la nouvel numero de telephone: ");
        fgets(contacts[existe].telephone, taille_telephone, stdin);
        contacts[existe].telephone[strcspn(contacts[existe].telephone,"\n")]='\0';

        test_telephone=0;
        if(strlen(contacts[existe].telephone)!=10)
                test_telephone=1;
        else
        {
            for(int i=0; i < strlen(contacts[existe].telephone); i++)
            {
                if(contacts[existe].telephone[i]<'0' || contacts[existe].telephone[i]>'9')
                    test_telephone=1;
            }
        }

        if( test_telephone || contacts[existe].telephone[0]!='0' || (contacts[existe].telephone[1]!='5' && contacts[existe].telephone[1]!='6' && contacts[existe].telephone[1]!='7')  )
            printf(RED"format invalid!\n");
    }while(test_telephone || contacts[existe].telephone[0]!='0' || (contacts[existe].telephone[1]!='5' && contacts[existe].telephone[1]!='6' && contacts[existe].telephone[1]!='7') ); 
        
        
    do
    {
        printf(MAG"entrer l\'email: ");
        fgets(contacts[existe].email, taille, stdin);
        contacts[existe].email[strcspn(contacts[existe].email,"\n")]='\0';
        test_email=strstr(contacts[existe].email,"@gmail.com");

        if(test_email==NULL || *(test_email+10)!='\0')
            printf(RED"format invalide!\n");
    } while (test_email == NULL || *(test_email+10)!='\0');
    
    printf(GRN"contact modifie avec succe!\n");   
}

void supprimer(contact contacts[])
{
    char nom[taille];
    int existe, choix;

    while(getchar()!='\n');
    do
    {
        printf(MAG"entrer le nom du contact a supprimer");
        fgets(nom,taille,stdin);
        nom[strcspn(nom,"\n")]='\0';

        if((existe=rechercher_nom(contacts, nom))==-1)
            printf(RED"contact introuvable!\n");

    }while(existe==-1);

    do
    {
        printf(MAG"entrer 1 pour confirmer, ou 0 pour annuler la suppression");
        scanf("%d", &choix);

        if(!choix)
            return;
    }while(choix!=0 && choix!=1);

    for(int i=existe; i<enregistre; i++)
    {
        contacts[i]= contacts[i+1];
        contacts[i].id--;
    }
    enregistre--;
    
    printf(GRN"contact supprime avec succe!\n");   
}

