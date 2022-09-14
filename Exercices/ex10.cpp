#include <iostram>
using namespace std;

struct Date
{
    unsigned int jour, mois, annee;
};

void ModifieDatePointeur(Date *d, unsigned int j, unsigned int m, unsigned int a)
{
    if (j > 31 || m > 12)
    {
        throw "Erreur : la date n'est pas valide";
    }
    else
    {
        d->jour = j;
        d->mois = m;
        d->annee = a;
    }
}

void ModifieDateRef(Date &d, unsigned int j, unsigned int m, unsigned int a)
{
    if (j > 31 || m > 12)
    {
        throw "Erreur : la date n'est pas valide";
    }
    else
    {
        d.jour = j;
        d.mois = m;
        d.annee = a;
    }
}

void ModifieDateValeur(Date d, unsigned int j, unsigned int m, unsigned int a)
{
    if (j > 31 || m > 12)
    {
        throw "Erreur : la date n'est pas valide";
    }
    else
    {
        d.jour = j;
        d.mois = m;
        d.annee = a;
    }
    return d;
}
