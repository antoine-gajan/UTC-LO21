#include "ex16.h"
#include <iostream>

using namespace std;

/*
Ecrire des fonctions qui permettent d'incrémenter un entier, un double,
un caractère, un tableau d'entiers, un tableau de double et un tableau de caractères

*/

void incrementer(int &a)
{
    a ++;
}

void incrmeenter (char& a)
{
    a++;
}

void incrementer(double& a)
{
    a ++;
}

void incrementer (int *tab, unsigned int n)
{
    for (unsigned int i = 0; i < n; i ++)
    {
        incrementer(tab[i]);
    }
}

void incrementer (double *tab, unsigned int n)
{
    for (unsigned int i = 0; i < n; i ++)
    {
        incrementer(tab[i]);
    }
}

void incrementer (double *tab, unsigned int n)
{
    for (unsigned int i = 0; i < n; i ++)
    {
        incrementer(tab[i]);
    }
}
