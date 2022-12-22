#include <iostream>
#include <algorithm>
#include "evenement.h"

using namespace std;
using namespace TIME;

std::ostream& operator<<(std::ostream& f, const Evt& e)
{
    e.afficher(f);
    return f;
}


Agenda &Agenda::operator<<(Evt &e) {
    for (auto evenement: tab) {
        evenement->afficher();
    }
}

Date getDate(const Evt& e)
{
    const Evt1j* pt = dynamic_cast<const Evt1j*>(&e);
    if (pt) return pt->getDate();
    const EvtPj* pt2 = dynamic_cast<const EvtPj*> (&e);
    if (pt2) return pt2->getDateDebut();
}

bool operator<(const Evt& e1, const Evt& e2){
    Date d1 = getDate(e1);
    Date d2 = getDate(e2);
    if (d1 < d2) return true;
    if (d2 < d1) return false;
    // Si les dates sont égales, on compare les horaires
    const Evt1jDur* pt1 = dynamic_cast<const Evt1jDur*>(&e1);
    const Evt1jDur *pt2 = dynamic_cast<const Evt1jDur*>(&e2);
    if (pt2 && !pt1) return true;
    if (pt1 && !pt2) return false;
    if (pt1 && pt2) return pt1->getHoraire() < pt2->getHoraire();
    return false;
}
