//Exercice 20 - M�thodes

//Une personne est d�finie par son sexe, nom, pr�nom, date de naissance et situation familiale
//Cr�er les accesseurs en m�thode inline

#include <iostream>
#include "ex20.h"

//M�thode de la classe Personne

unsigned int Personne::age (unsigned int annee_en_cours) const
{
    return annee_en_cours - annee_naissance;
}
