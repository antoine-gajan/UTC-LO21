#ifndef CLION_EX38_H
#define CLION_EX38_H

#include <string>
#include <iostream>

using namespace std;

// 1. Rédifinir l'affichage de mission pour avoir aussi la priorité

class tache {
public:
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



#endif //CLION_EX38_H
