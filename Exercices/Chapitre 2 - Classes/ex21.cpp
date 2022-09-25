//Exercice 21 - Constructeur

//Une personne est définie par son sexe, nom, prénom, date de naissance et situation familiale
//Créer le constructeur qui initialise tous les attributs

#include <iostream>
#include "ex21.h"

//Méthode de la classe Personne

unsigned int Personne::age (unsigned int annee_en_cours) const
{
    return annee_en_cours - annee_naissance;
}

//Constructeur
Personne::Personne(const string& nom, const string& prenom, unsigned int annee_naiss, Sexe sexe, Situation situ)
{
    this.nom = nom;
    this.prenom = prenom;
    this.annee_naissance = annee_naiss;
    this.sexe = sexe;
    this.situation = situ;
}
