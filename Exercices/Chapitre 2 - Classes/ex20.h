//Exercice 20 - M�thodes

//Une personne est d�finie par son sexe, nom, pr�nom, date de naissance et situation familiale
//Cr�er les accesseurs en m�thode inline

#include <iostream>
#include <string>

enum Sexe {homme, femme};
enum Situation {marie, veuf};

class Personne()
{
private:
    std::string nom;
    std::string prenom;
    unsigned int annee_naissance;
    Sexe sexe;
    Situation situation;
//M�thodes inlines pour les accesseurs
public:
    string getNom() const {return nom;}
    string getPrenom() const {return prenom;}
    unsigned int getAnneeNaissance() const {return annee_naissance;}
    Sexe getSexe() const {return sexe;}
    Situation getSituation() const {return situation;}
    unsigned int age(unsigned int annee_en_cours) const;
};
