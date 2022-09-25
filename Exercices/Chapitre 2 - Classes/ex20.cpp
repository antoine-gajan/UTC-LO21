//Exercice 20 - Méthodes

//Une personne est définie par son sexe, nom, prénom, date de naissance et situation familiale
//Créer les accesseurs en méthode inline

#include <iostream>
#include "ex20.h"

//Méthode de la classe Personne

unsigned int Personne::age (unsigned int annee_en_cours) const
{
    return annee_en_cours - annee_naissance;
}
