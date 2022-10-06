//Exercice 24 - Utilisation sstream

//Une personne est d�finie par son sexe, nom, pr�nom, date de naissance et situation familiale
//Affiche une phrase
#include <iostream>
#include <sstream>
#include <string>
#include "ex24.h"

using namespace std;

//M�thode de la classe Personne

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
    sb << (sexe == homme? "M. " : "Mme ") << nom <<" "<< prenom << " est "<< (sexe == homme ? "n�" : "n�e") << " en " << annee_naissance;
    sb << (sexe == homme? " il" : " elle") << " est ";
    if (sexe == homme)
    {
        if (situation == marie)
        {
            sb << "mari�.";
        }
        else if (situation == celibataire)
        {
            sb << "c�libataire.";
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
            sb << "mari�e.";
        }
        else if (situation == veuf)
        {
            sb << "veuve.";
        }
        else
        {
            sb << "c�libataire.";
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
