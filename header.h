#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct scooter Scooter;

struct scooter
{
    char id[10];
    int etat;
    float kilom;
    Date d;
};

typedef struct date Date;
struct date
{
    int jour;
    int mois;
    int annee;   
};

typedef struct Cellule* liste;
typedef struct Cellule Cellule;

struct Cellule
{
    Scooter s;
    struct Cellule* suivant;
};

typedef struct
{
    struct Cellule* tete;
    struct Cellule* queu;
} file;


void saisirscooter(Scooter *s);
Cellule* chercherScooter(liste l,char id[]);
liste ajouterScooter(liste l,Scooter s);
void louerscooter(liste l,char id[]);
void afficherscooter(liste l,char nomFichier[]);
file enfilerScooter(liste l,file f,char id[]);
void entretenirscooter(file *f,liste l);
Arbre insererScooters(Arbre A,Scooter s);
Arbre construireArbre(Arbre A,liste l);
Arbre maxScooters(Arbre A);

#endif // PILE_FILE_H_INCLUDED

