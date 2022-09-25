//Exercice 20 - Méthodes

//Une personne est définie par son sexe, nom, prénom, date de naissance et situation familiale
//Créer les accesseurs en méthode inline

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
//Méthodes inlines pour les accesseurs
public:
    string getNom() const {return nom;}
    string getPrenom() const {return prenom;}
    unsigned int getAnneeNaissance() const {return annee_naissance;}
    Sexe getSexe() const {return sexe;}
    Situation getSituation() const {return situation;}
    unsigned int age(unsigned int annee_en_cours) const;
};
