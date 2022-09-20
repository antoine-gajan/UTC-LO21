#include <iostream>
using namespace std;

int main()
{
    //Création du tableau
    double *pointeur = new double[20];
    //Affectation
    for (int i = 0; i < 20; i++)
    {
        pointeur[i] = 3.14;
    }
    //Desallocation mémoire
    delete[] pointeur;
    return 0;
}
