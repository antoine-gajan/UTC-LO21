//Exercice 26 - Classe vecteur
#include <iostream>
#include "ex26.h"

using namespace std;

Vecteur::Vecteur(unsigned int n) :dim(n), tab(new double[n]) 
{
	for (size_t i = 0; i < dim; i++)
	{
		tab[i] = 0;
	}
}

Vecteur::~Vecteur()
{
	delete[] tab;
}

