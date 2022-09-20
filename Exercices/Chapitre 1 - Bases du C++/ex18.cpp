/*
Exercice 18

Reprendre les fonctions de l'exercice 17, les mettre dans un namespace FX
Puis utiliser une using declaration, une using directive et une résolution de portée
*/

#include <iostream>

using namespace std;

namespace FX
{
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
}

int main()
{
    int a = 8;
    char b = 8:
    double c = 4.1;
    FX::incrementer(a); //resolution de portée
    using FX::incrementer; // using declaration
    increment(b);
    using namespace FX; // using directive, inutile ici
    increment(c);
}
