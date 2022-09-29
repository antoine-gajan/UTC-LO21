#include "fraction.h"
#include <iostream>

// Constructeur (question 1)
MATH::Fraction::Fraction(int num, int den)
{
	setFraction(num, den);
	std::cout << "La fraction stockee à l'adresse " << this << " vient d'etre cree.\n";

}
/*
2ème méthode : avec initialisation
MATH::Fraction::Fraction(int num, int den) : numerateur(num), denominateur(den)
{
	setFraction();
	simplification();
}
*/


// Accesseur (question 2)
void MATH::Fraction::setFraction(int n, int d)
{
	if (d == 0)
	{
		// Lance une exception
		throw MATH::FractionException("Erreur : le dénominateur ne peut pas être nul !\n");
	}
	numerateur = n;
	denominateur = d;
	// Simplification de la fraction
	simplification();
}

// Fonction pour simplifier une fraction
void MATH::Fraction::simplification() {
	// si le numerateur est 0, le denominateur prend la valeur 1
	if (numerateur == 0) { denominateur = 1; return; }
	/* un denominateur ne devrait pas être 0;
	si c’est le cas, on sort de la méthode */
	if (denominateur == 0) return;
	/* utilisation de l’algorithme d’Euclide pour trouver le Plus Grand Commun
	Denominateur (PGCD) entre le numerateur et le denominateur */
	int a = numerateur, b = denominateur;
	// on ne travaille qu’avec des valeurs positives...
	if (a < 0) a = -a; if (b < 0) b = -b;
	if (denominateur == 1) return;
	while (a != b) { if (a > b) a = a - b; else b = b - a; }
	// on divise le numerateur et le denominateur par le PGCD=a
	numerateur /= a; denominateur /= a;
	// si le denominateur est négatif, on fait passer le signe - au numérateur
	if (denominateur < 0) { denominateur = -denominateur; numerateur = -numerateur; }
}

// Question 5 : somme de 2 fractions
MATH::Fraction MATH::Fraction::somme(const Fraction& a) const
{
	return Fraction(numerateur * a.denominateur + a.numerateur * denominateur, denominateur * a.denominateur);
}

// Question 6 : destructeur
MATH::Fraction::~Fraction()
{
	std::cout << "La fraction stockee à l'adresse " << this << " est supprimee.\n";
}

// Exercice 21 : surcharge d'opérateurs

MATH::Fraction MATH::operator+ (const Fraction& a, const Fraction& b)
{
	return a.somme(b);
}

MATH::Fraction MATH::operator- (const Fraction& a, const Fraction& b)
{
	return Fraction(a.getNumerateur() * b.getDenominateur() - b.getNumerateur() * a.getDenominateur(), a.getDenominateur() * b.getDenominateur());
}

MATH::Fraction& MATH::Fraction::operator++()
{
	*this = *this + 1;
	return *this;
}

MATH::Fraction& MATH::Fraction::operator--()
{
	*this = *this - 1;
	return *this;
}

MATH::Fraction& MATH::operator++(Fraction& a, int )
{
	Fraction old = a;
	a = a + 1;
	return old;
}

MATH::Fraction& MATH::operator--(Fraction& a, int b)
{
	Fraction old = a;
	a = a - 1;
	return old;
}

std::ostream& MATH::operator<<(std::ostream& flux, const MATH::Fraction& f)
{
	if (f.denominateur != 1)
	{
		flux << f.numerateur << "\n";
	}
	else if (f.numerateur == 0)
	{
		flux << "0 \n";
	}
	else
	{
		flux << f.numerateur << " / " << f.denominateur << "\n";
	}
	return flux;
}


/*
Notes de cours :

++a => a.operator++()
    => operator++(a)

a++ => a.operator++(int)
    => operator++(a, int)

int est argument fictif

*/

