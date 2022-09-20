#include "ex14.h"
#include <iostream>
/*
Après avoir placé les déclarations de cette structure dans le fichier d'en-tête fonction.h, faire les modfications
nécessaire pour simplifier le programme suivant en utilisant les nouvelles possibilités du C++. Ajouter aussi les
déclarations qui semblent utiles dans le fichier d'entête.

 */

void point::init(int _x, int _y, int _z) {
    x=_x; y=_y; z=_z;
}

void init(point* pt, int _x, int _y, int _z)
{
    pt->x = _x; pt->y = _y; pt->z = _z;
}

void essai_init() {
    point p;
    init(&p);
    init(&p,1);
    init(&p,1,2);
    init(&p,1,2,3);
}
