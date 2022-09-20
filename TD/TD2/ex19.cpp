#include "ex19.h"

#include <iostream>
#include <string>

using namespace std;
/*
Ecrire une fonction operation qui permet de faire les opérations suivantes en leur donnant du sens.
Le premier argument de cette fonction est un tableau de de structure de type compte. Le deuxième argument est
une chaîne de caractères qui permet d'identier dans ce tableau le compte particulier à utiliser : il s'agit de celui
dont le champs id est égal à cette chaîne. Il s'agit de faire en sorte que le solde du compte soit modié conformément
à l'opération souhaitée. On supposera que le compte voulu par l'utilisateur existe bien dans le tableau.
 */

int& operation(compte * tab, string id)
{
    int i = 0;
    while (tab[i].id != id)
    {
        i ++;
    }
    return tab[i].solde;
}

void essai_comptes(){
    compte tab[4]={ {"courant", 0},{"codevi", 1500 },
                    {"epargne", 200 }, { "cel", 300 } };
    operation(tab,"courant")=100;
    operation(tab,"codevi")+=100;
    operation(tab,"cel")-=50;
    for(int i=0; i<4; i++) cout<<tab[i].id<<" : "<<tab[i].solde<<"\n";
}

int main()
{
    essai_comptes();
}

