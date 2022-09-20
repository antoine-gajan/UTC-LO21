#include "ex17.h"
#include <iostream>

using namespace std;
/*
Question 1
Écrire une fonction raz qui permet d'initialiser le champ nom et le champ age d'une variable de type personne
transmise en argument, respectivement avec la chaîne de caractères vide et la valeur 0.
 */

void initialiser(personne& p)
{
    p.age = 0;
    p.nom[0] = '\0';
}

/*
 Question 2
Écrire une fonction affiche_struct qui permet d'acher les attributs d'une donnée de type personne transmise
en argument.
 */

void affiche_struct(const personne &p)
{
    cout << "Age = " << p.age << "\n";
    cout << "Nom = " << p.nom << "\n";
}

/*
Question 3
Écrire une fonction affiche_tab qui permet d'acher les attributs d'un tableau de personne dont l'adresse et
le nombre d'éléments sont passés en argument.
 */

void affiche_tab(const personne * tab, int taille)
{
    for (int i = 0; i < n; i++)
    {
        affiche_struct(tab[i]);
    }
}


/*
Question 4
Écrire une fonction init_struct qui permet d'initialiser une structure dont l'adresse est passée en argument avec
une chaîne de caractères et un entier passés en arguments. Ne pas utiliser de fonction de type strcpy pour cet
exercice.
 */

void init_struct(personne &p, const char *nom, int age)
{
    p.age = age;
    int i = 0;
    while (nom[i] != '\0')
    {
        p.nom[i] = nom[i];
    }
    p.nom[i] = '\0';
}

/*
Question 5
Écrire une fonction copy_struct qui permet de copier les diérents champs d'une donnée de type personne
dans une autre donnée de type personne.
 */

void copy_struct(personne &p1, personne &p2)
{
    p1.age = p2.age;
    int i = 0;
    while (p2.nom[i] != '\0')
    {
        p1.nom[i] = p2.nom[i];
    }
    p1.nom[i] = '\0';
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




