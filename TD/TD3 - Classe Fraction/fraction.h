#pragma once
#include <iostream>
#include <string>

// Question 1

namespace MATH
{
	class Fraction
	{
	private:
		int numerateur;
		int denominateur;
		
	public:
		Fraction(int num = 0, int den = 1);
		// Question 2
		int getNumerateur() const { return numerateur; };
		int getDenominateur() const { return denominateur; };
		void setFraction(int n, int d);
		// Question 4
		void simplification();
		~Fraction();
		// Question 5
		Fraction somme(const Fraction& a) const;
		// Surchage ++
		Fraction& operator++();
		//Surcharge --
		Fraction& operator--();
		//Surcharge <<
		friend std::ostream& operator<<(std::ostream& flux, const Fraction& f);
	};
	//Exercice 21 : surcharge d'opérateurs
	Fraction operator+ (const Fraction& a, const Fraction& b);
	Fraction operator- (const Fraction& a, const Fraction& b);

	// Surchage ++
	Fraction& operator++(Fraction& a, int);
	//Surcharge --
	Fraction& operator--(Fraction& a, int);


	//Exercice 22 : Gestion des exceptions
	class FractionException
	{
	private:
		std::string info;
	public:
		std::string getInfo() const { return info; };
		FractionException(const std::string& exception) : info(exception){};
	};
}

