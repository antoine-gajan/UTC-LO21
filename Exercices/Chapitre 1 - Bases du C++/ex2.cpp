//Ecrire un programme qui demande � l'utilisateur son pr�nom et qui lui dit "bonjour" en r�indiquant son pr�nom

#include <string>
#include <iostream>
using namespace std;

int main()
{
	cout<<"Quel est votre nom ?";
	string nom;
	cin>>nom;
	cout<<"Votre pr�nom est "<<nom<<" !";
	return 0;
}