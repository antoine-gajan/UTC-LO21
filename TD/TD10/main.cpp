#include <iostream>
#include "container.h"

int main() {
    using namespace TD;
    Vector<int> vecteur(10, 0);
    vecteur.push_back(12);
    vecteur.push_back(22);
    vecteur.push_back(32);
    vecteur.push_back(42);
    vecteur.pop_back();

    return 0;
}
