//Exercice 19 - Définition d'une classe Personne

//Une personne est définie par son sexe, nom, prénom, date de naissance et situation familiale

#include <iostream>
#include <string>

enum Sexe {homme, femme};
enum Situation {marie, veuf};

class Personne()
{
private:
    string nom;
    string prenom;
    unsigned int annee_naissance;
    Sexe sexe;
    Situation situation;
};
