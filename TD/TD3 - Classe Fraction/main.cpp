#include <iostream>
#include "fraction.h"
using namespace std;
using namespace MATH;
Fraction* myFunction() {
	Fraction fx(7, 8);
	Fraction* pfy = new Fraction(2, 3);
	return pfy;
}
int main() {
	try
	{
		Fraction f1(1, 0);
	}
	catch (FractionException e)
	{
		cout << e.getInfo() << endl;

	}
	Fraction f2(1, 6);
	Fraction* pf3 = new Fraction(1, 2);
	cout << "ouverture d置n bloc\n";
	Fraction* pf6;
	{
		Fraction f4(3, 8);
		Fraction f5(4, 6);
		pf6 = new Fraction(1, 3);
	}
	cout << "fin d置n bloc\n";
	cout << "debut d置ne fonction\n";
	Fraction* pf7 = myFunction();
	cout << "fin d置ne fonction\n";
	cout << "desallocations controlee par l置tilisateur :\n";
	delete pf6;
	delete pf7;
	return 0;
}