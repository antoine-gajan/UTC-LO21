//Adressage indirect

/*D�finir une variable x de type double en l'initialisant avec la valeur 3.14 et afficher sa valeur.
D�finir une variable pt de type pointeur de double qui sera initialis�e avec l'adresse de la variable x.
Modifier la valeur de x � partir du pointeur pt. Afficher la nouvelle valeur de x, une fois � partir de l'
identificateur x, une fois � partir du pointeur pt. Afficher l'adresse de x en utilisant le pointeur pt.
D�finir une variable r�f�rence ref qui sera initialis�e avec l'adresse de la variable x. Modifier la valeur de x
� partir de la r�f�rence ref. Afficher la nouvelle valeur de x, une fois � partir de l'identificateur x,
une fois � partir de la r�f�rence ref. Afficher l'adresse de x en utilisant la r�f�rence ref.
*/

#include <iostream>

int main()
{
	double x = 3.14;
	cout<<"Valeur de x : "<<x<<"\n";

	double *pt = &x;
	*pt = 1.12;
	cout<<"Premier affichage de x : "<<x<<"\n";
	cout<<"Deuxi�me affichage de x : "<<*pt<<"\n";

	double &ref = x;
	ref = 43.2;
	cout<<"Premier affichage de x : "<<x<<"\n";
	cout<<"Deuxi�me affichage de x : "<<&ref<<"\n";
}