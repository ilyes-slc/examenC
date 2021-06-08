#include "header.h"

void saisircompte(Compte *c){
    printf("numero: ");
    scanf("%d", &c->num);
    printf("nom: ");
    fflush(stdin);
    gets(c->nom);
    printf("type : ");
    scanf("%c", &c->type);
    scanf("%d", &c->date.jour);
    printf("sate : mois ?: ");
    scanf("%d", &c->date.mois);
    printf("sate : annee ?: ");
    scanf("%d", &c->date.annee);
}

Cellule* chercherCompte(LDC l, int num)
{
    Cellule *pC;

    if( LDC_vide(l) )
        return NULL;
    else
    {
        pC = l.tete;
        while( pC && (pC->c.num != num) )
            pC = pC->suiv;

        return (pC)? &pC->c : NULL;
    }
}

int LDC_vide(LDC l)
{
    return( l.tete == NULL && l.queu == NULL );
}

LDC ajouterCompte(LDC l, Compte c)
{
    Cellule* pNouv;

    pNouv = (Cellule*)malloc(sizeof(Cellule));
    if(!pNouv)
        printf("Espace memoire insuffisant\n");
    else
    {
        pNouv->c = c;
        pNouv->suiv = NULL;
        pNouv->prec = l.queu;
        if(!LDC_vide(l))
            l.queu->suiv = pNouv;
        else
            l.tete = pNouv;
        l.queu = pNouv;
    }
    return l;
}

void afficherCompte(LDC l){
    Cellule *pC = NULL;
    int i = 0;

    if( LDC_vide(l) )
        printf("Liste vide\n");
    else
    {
        pC = l.tete;
        while(pC)
        {
            printf("numero : %d - solde : %d\n", ++i, pC->c.num,pC->c.solde);
            pC = pC->suiv;
        }
    }
}


void sauvegarderCompte(LDC l,char nomFichier[]){
    Cellule *pC = NULL;
    int i = 0;
    Compte *t = (Compte*)malloc(20*sizeof(Compte));
    FILE* fp;
    fp = fopen(nomFichier, "wb"); 

    if( LDC_vide(l) )
        printf("Liste vide\n");
    else
    {
        pC = l.tete;
        while(pC)
        {
            

            t[i]=pC->c; 
            pC = pC->suiv;
            i++;
        }
            fwrite(t, sizeof(Compte), i, fp);

    free(t);
    fclose(fp);
    }
}

Arbre inserer(Arbre a,Compte c){

    
        if (c.solde <= a->c.solde)
            a->pL = inserer(a->pL, c);
        else
            a->pR = inserer(a->pR, c);
    
    return a;
}

Arbre remplirArbre(Arbre  a, LDC l){
    Cellule *pC = NULL;
    int i = 0;

    if( LDC_vide(l) )
        printf("Liste vide\n");
    else
    {
        pC = l.tete;
        while(pC)
        {
            inserer(a,pC->c);
            pC = pC->suiv;
        }
    }

}

void afficher(Arbre a)
{
    if ( a != NULL )
    {
        afficher(a->pR);
        printf("\tNom: %s\tNum: %d\t\ttype: %d\tsolde: %.2f\n",
               a->c.nom, a->c.num, a->c.type, a->c.solde);
        afficher(a->pL);
    }
}

int calculerNbr (Arbre a,float montant){
    int i=0;
    if ( a != NULL )
    {
        calculerNbr(a->pR,montant);
        if (a->c.solde > montant)
        {
            i++;
        }
        
        calculerNbr(a->pL,montant);
    }
    return i;
}