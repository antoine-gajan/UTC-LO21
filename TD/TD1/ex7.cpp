#include <iostream>

using namespace std;

int main()
{
    //D�finir une constante pi x � la valeur 3.14
    const double pi = 3.14;
    cout << "Valeur de pi : "<< pi;
    //Essai d'affectation d'une nouvelle valeur (qui va provoquer une erreur)
    pi = 4.2;
    return 0;
}
