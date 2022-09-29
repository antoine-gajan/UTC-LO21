//Exercice 22 - Allocation dynamique

//Une personne est définie par son sexe, nom, prénom, date de naissance et situation familiale
//Allouer une personne dynamiquement
#include <iostream>
#include "ex21.h"

using namespace std;

//Méthode de la classe Personne

unsigned int Personne::age (unsigned int annee_en_cours) const
{
    return annee_en_cours - annee_naissance;
}

//Constructeur
Personne::Personne(const string& n, const string& p, unsigned int a, Sexe sex, Situation situ)
{
    nom = n;
    prenom = p;
    annee_naissance = a;
    sexe = sex;
    situation = situ;
}

int main()
{
    Personne *p = new Personne("gajan", "antoine", 2003, homme, marie);
    delete p;
    return 0;
}
