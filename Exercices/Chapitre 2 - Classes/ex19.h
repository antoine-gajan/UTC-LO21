//Exercice 19 - D�finition d'une classe Personne

//Une personne est d�finie par son sexe, nom, pr�nom, date de naissance et situation familiale

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
