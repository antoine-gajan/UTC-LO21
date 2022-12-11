#ifndef CLION_EX43_H
#define CLION_EX43_H


#include <string>
#include <iostream>

using namespace std;

// 1. Créer une classe abstraite affichable avec une méthode void afficher(ostream& f) const
// 2. Définir une classe truc composant un attribut de type int, qui hérite de la classe affichable, dont il est possible d'instancier des objets
// 3. Tache doit maintenant hériter de affichable

class affichable {
public:
    virtual void afficher(ostream& f=cout) const = 0;
};

class truc : public affichable {
private:
    unsigned int nb;
public:
    virtual void afficher(ostream& f=cout) const {f << nb;}
};

class tache : affichable {
protected:
    tache(const string& n, unsigned int d=0) : nom(n), duree(d){}
    virtual void afficher(ostream& f=cout) const {f << "tache " << nom << ": duree ="<<duree;}
    const string& get_nom() const {return nom;}
    unsigned int get_duree() const {return duree;}
private:
    string nom;
    unsigned int duree;
};

class mission : public tache {
private:
    unsigned int priorite;
public:
    unsigned int get_priorite() const {return priorite;}
    mission(const string& n, unsigned int d = 0, unsigned int p = 0) : tache(n, d), priorite(0) {}
    virtual void afficher(ostream& f=cout) const {tache::afficher(f); f << "priorite = " << priorite;}
};



#endif //CLION_EX43_H
