//Exercice 24 - Utilisation sstream

//Une personne est définie par son sexe, nom, prénom, date de naissance et situation familiale
//Affiche une phrase
#include <iostream>
#include <sstream>
#include <string>
#include "ex24.h"

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

string Personne::retourneInfos() const
{
    stringstream sb;
    sb << (sexe == homme? "M. " : "Mme ") << nom <<" "<< prenom << " est "<< (sexe == homme ? "né" : "née") << " en " << annee_naissance;
    sb << (sexe == homme? " il" : " elle") << " est ";
    if (sexe == homme)
    {
        if (situation == marie)
        {
            sb << "marié.";
        }
        else if (situation == celibataire)
        {
            sb << "célibataire.";
        }
        else
        {
            sb << "veuf.";
        }
    }
    else
    {
        if (situation == marie)
        {
            sb << "mariée.";
        }
        else if (situation == veuf)
        {
            sb << "veuve.";
        }
        else
        {
            sb << "célibataire.";
        }
    }
    return sb.str();
}

int main()
{
    Personne *p = new Personne("gajan", "antoine", 2003, homme, celibataire);
    cout << p->retourneInfos();
    delete p;
    return 0;
}
