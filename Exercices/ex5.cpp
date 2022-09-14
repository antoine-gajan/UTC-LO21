//Adressage indirect

/*Définir une variable x de type double en l'initialisant avec la valeur 3.14 et afficher sa valeur.
Définir une variable pt de type pointeur de double qui sera initialisée avec l'adresse de la variable x.
Modifier la valeur de x à partir du pointeur pt. Afficher la nouvelle valeur de x, une fois à partir de l'
identificateur x, une fois à partir du pointeur pt. Afficher l'adresse de x en utilisant le pointeur pt.
Définir une variable référence ref qui sera initialisée avec l'adresse de la variable x. Modifier la valeur de x
à partir de la référence ref. Afficher la nouvelle valeur de x, une fois à partir de l'identificateur x,
une fois à partir de la référence ref. Afficher l'adresse de x en utilisant la référence ref.
*/

#include <iostream>

int main()
{
	double x = 3.14;
	cout<<"Valeur de x : "<<x<<"\n";

	double *pt = &x;
	*pt = 1.12;
	cout<<"Premier affichage de x : "<<x<<"\n";
	cout<<"Deuxième affichage de x : "<<*pt<<"\n";

	double &ref = x;
	ref = 43.2;
	cout<<"Premier affichage de x : "<<x<<"\n";
	cout<<"Deuxième affichage de x : "<<&ref<<"\n";
}