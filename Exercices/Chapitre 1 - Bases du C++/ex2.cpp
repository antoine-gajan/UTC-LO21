//Ecrire un programme qui demande à l'utilisateur son prénom et qui lui dit "bonjour" en réindiquant son prénom

#include <string>
#include <iostream>
using namespace std;

int main()
{
	cout<<"Quel est votre nom ?";
	string nom;
	cin>>nom;
	cout<<"Votre prénom est "<<nom<<" !";
	return 0;
}