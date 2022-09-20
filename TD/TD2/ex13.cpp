/* Ecrire une fonction nommée raz permettant de remettre à zéro les 2 champs d'une structure de ce type transmise
en argument.
Faire l'exercice une fois en utilisant un passage par adresse, une fois en utilisant un passage par référence. Dans
les deux cas, on écrira un petit programme d'essai de la fonction. Il achera les valeurs d'une structure de ce type
après appel de la dite fonction.
 */

#include <iostream>
using namespace std;

struct essai {
    int n;
    float x;
};

void raz(essai &e)
{
    e.n = 0;
    e.x = 0;
}

void raz(essai *e)
{
    e->n = 0;
    e->x = 0;
}

int main()
{
    essai test;
    test.x = 14.4;
    test.n = 12;
    cout << "x = " << test.x << " n = " << test.n << "\n";
    raz(test);
    cout << "x = " << test.x << " n = " << test.n << "\n";
    test.x = 14.4;
    test.n = 12;
    cout << "x = " << test.x << " n = " << test.n;
    raz(&test);
    cout << "x = " << test.x << " n = " << test.n;
    return 0;
}