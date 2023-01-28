#include <iostream>
#include <algorithm>
#include "fonction.h"

using namespace std;

std::ostream& operator<<(std::ostream& f, const TIME::Evt1j& e)
{
    e.afficher(f);
    return f;
}

TIME::Agenda &TIME::Agenda::operator<<(TIME::Evt1j &e) {
    tab.push_back(&e);
    return *this;
}

void TIME::Agenda::afficher(ostream &f) const {
    for (auto evenement : tab){
        evenement->afficher();
    }
}
