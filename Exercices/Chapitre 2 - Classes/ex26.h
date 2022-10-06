//Exercice 25 - Classe vecteur

#include <iostream>


class Vecteur
{
private:
	double* tab;
	unsigned int dim;
public:
	Vecteur(unsigned int n);
	~Vecteur();
};
