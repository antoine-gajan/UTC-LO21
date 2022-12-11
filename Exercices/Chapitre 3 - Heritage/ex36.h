#ifndef CLION_EX36_H
#define CLION_EX36_H

#include <iostream>
#include <string>

using namespace std;

// 1.Créer une classe mission qui est une tâche munie d'une priorité se caractérisant par un entier positif
// 2.Définir toute fonction nécessaire à la création d'un objet mission


class tache {
public:
    tache(const string& n, unsigned int d=0) : nom(n), duree(d){}
    void afficher(ostream& f=cout) const {f << "tache " << nom << ": duree ="<<duree;}
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
};

#endif //CLION_EX36_H
