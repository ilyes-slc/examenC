#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    Arbre a;
    LDC l;
    char id[10];
    Compte c;
    int choix,i;
    float montant;
    do
    {
        do
        {
            printf("1. ajouter.\n");
            printf("2. afficher.\n");
            printf("3. operation.\n");
            printf("4. sauvegarder les comptes.\n");
            printf("5. remplir larbre.\n");
            printf("6. afficher les comptes.\n");
            printf("7. afficher le nombre des comptes ayant un solde superieur a un montant.\n");
            printf("0. Quitter.");
            scanf("%d", &choix);
        }while( choix<0 || choix>8 );

        switch(choix)
        {
            case 1:
                saisirCompte(&c);
                ajouterCompte(l,c);
                break;

            case 2:
                afficherCompte(l);
                break;

            case 3:
                //op
                break;

            
            case 4:
            sauvegarderCompte (l , "comptes.bin");
                break;

         
            case 5:
              remplirArbre(a,l);

            case 6:
                
              afficher(a);  
         break;

            case 7:
                printf("donner le montant\n");
            scanf("%f",&montant);
            i=calculerNbr(a,montant); 
            printf("%d",i);
                break;

        

            case 0:
                break;

            default:
                break;
        }
    }while( choix!=0 );

    return 0;
}