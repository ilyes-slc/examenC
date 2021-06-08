#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct compte Compte;

struct compte
{
    char nom[10];
    int num;
    char type;
    float solde;
    Date date;
};

typedef struct date Date;
struct date
{
    int jour;
    int mois;
    int annee;   
};

typedef struct cellule Cellule;
typedef struct listeDC LDC;

struct cellule
{
    Compte c;
    struct cellule* suiv;
    struct cellule* prec;
};

struct listeDC
{
    Cellule* tete;
    Cellule* queu;
};

typedef struct noeud* Arbre;

struct noeud
{
    Compte c;
    struct noeud* pL;
    struct noeud* pR;
};



void saisirCompte (Compte *c );

Cellule * chercherCompte(LDC l ,int num);

int LDC_vide(LDC l);


LDC ajouterCompte(LDC l, Compte c);


 void Operation (LDC,int num , float montant,char operation , Date d);


 void afficherCompte (LDC l);

 void sauvegarderCompte (LDC L , char nomfichier[]);

 Arbre inserer (Arbre a,Compte c);

 Arbre remplirArbre (Arbre a,LDC l);

 void afficher (Arbre a);

 int calculerNbr (Arbre a, float montant);

#endif // PILE_FILE_H_INCLUDED

