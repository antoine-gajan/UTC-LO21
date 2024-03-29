//Exercice 21 - Constructeur

//Une personne est d�finie par son sexe, nom, pr�nom, date de naissance et situation familiale
//Cr�er le constructeur qui initialise tous les attributs

#include <iostream>
#include "ex21.h"

using namespace std;

//M�thode de la classe Personne

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
