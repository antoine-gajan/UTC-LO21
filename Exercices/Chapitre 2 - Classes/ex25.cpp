//Exercice 25 - Ajout du conjoint et possibilité de divorce

//Une personne est définie par son sexe, nom, prénom, date de naissance et situation familiale
//Affiche une phrase
#include <iostream>
#include <sstream>
#include <string>
#include "ex25.h"

using namespace std;

//Méthode de la classe Personne

unsigned int Personne::age (unsigned int annee_en_cours) const
{
    return annee_en_cours - annee_naissance;
}

//Constructeur
Personne::Personne(const string& n, const string& p, unsigned int a, Sexe sex, Situation situ) : nom(n), prenom(p), annee_naissance(a), sexe(sex), situation(situ), conjoint(nullptr)
{    
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

void Personne::mariageAvec(Personne& c)
{
    if (this != &c && c.conjoint == nullptr && conjoint == nullptr)
    {
        conjoint = &c;
        c.conjoint = this;
        c.situation = marie;
        situation = marie;
    }
    else
    {
        throw "Erreur : mariage impossible";
    }

}

void Personne::divorce()
{
    if (conjoint != nullptr)
    {
        conjoint->conjoint = nullptr;
        conjoint->situation = celibataire;
        conjoint = nullptr;
        situation = celibataire;
    }
    else
    {
        throw "Erreur : un célibataire ne peut pas divorcer";
    }

}

Personne::~Personne()
{
    if (conjoint != nullptr)
    {
        conjoint->conjoint = nullptr;
        conjoint->situation = veuf;
    }
}

int main()
{
    Personne *p = new Personne("gajan", "antoine", 2003, homme, celibataire);
    cout << p->retourneInfos();
    delete p;
    return 0;
}
