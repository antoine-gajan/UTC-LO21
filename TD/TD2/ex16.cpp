/*
Expliquer pourquoi le programme suivant ne peut pas être compilé :

#include<array>
using namespace std;
int calcul(int x) { return 2 * x + 1; }
int getNumber() { return 3; }
int main() {
const int N = getNumber();
array<int,calcul(N)> tableau;
return 0;
}

 Transformer le programme ci-dessus en utilisant des variables et des fonctions constexpr de façon à pouvoir le
compiler.
 */

#include <iostream>
#include <array>

using namespace std;

//Variable constexpr = variable constante qu'on peut calculer à la compilation et non à l'execution
constexpr int calcul(int x) { return 2 * x + 1; }
constexpr int getNumber() { return 3; }
int main() {
    constexpr int N = getNumber();
    array<int,calcul(N)> tableau;
    return 0;
}