#include "ex17.h"
#include <iostream>
#include <string>

using namespace std;

//Transformer l'exercice 17 avec le type string

void initialiser(personne& p)
{
    p.age = 0;
    p.nom = "";
}



void affiche_struct(const personne &p)
{
    cout << "Age = " << p.age << "\n";
    cout << "Nom = " << p.nom << "\n";
}



void affiche_tab(const personne * tab, int taille)
{
    for (int i = 0; i < n; i++)
    {
        affiche_struct(tab[i]);
    }
}



void init_struct(personne &p, const char *nom, int age)
{
    p.age = age;
    p.nom = nom;
}


void copy_struct(personne &p1, personne &p2)
{
    p1.age = p2.age;
    p1.nom = p2.nom;
}

/*
Question 6
Écrire une fonction copy_tab qui permet de copier un tableau de variables de type personne dans un autre
tableau du même type.
 */


void copy_tab(personne *tabdes, personne *tabsource, size_t n)
{
    for (size_t i = 0; i < n ; i++)
    {
        copy_struct(tabdes[i], tabsource[i]);
    }
}





