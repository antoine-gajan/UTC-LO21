//Réécriture d'un programme C en C++

#include<iostream>
using namespace std;

void exercice5(){
int r; double p, s;
double const pi = 3.14;
cout << "donnez le rayon entier d’un cercle: ";
cin >> r;
p=2*pi*r;
s=pi*r*r;
cout << "le cercle de rayon "<< r<< " a un perimetre de "<< p << " et une surface de "<< s ;
}

//Programme principal
int main()
{
    exercice5();
    return 0;
}
