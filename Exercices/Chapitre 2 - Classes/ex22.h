//Exercice 22 - Allocation dynamique

//Une personne est d�finie par son sexe, nom, pr�nom, date de naissance et situation familiale
//Cr�er un constructeur

#include <iostream>
#include <string>

enum Sexe {homme, femme};
enum Situation {marie, veuf};

class Personne
{
private:
    std::string nom;
    std::string prenom;
    unsigned int annee_naissance;
    Sexe sexe;
    Situation situation;
//M�thodes inlines pour les accesseurs
public:
    std::string getNom() const {return nom;}
    std::string getPrenom() const {return prenom;}
    unsigned int getAnneeNaissance() const {return annee_naissance;}
    Sexe getSexe() const {return sexe;}
    Situation getSituation() const {return situation;}
    unsigned int age(unsigned int annee_en_cours) const;
    //Ajout du constructeur
    Personne(const std::string& nom, const std::string& prenom, unsigned int annee_naiss, Sexe sexe, Situation situ);
};
