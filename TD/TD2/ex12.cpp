//Ecrire une fonction qui permet d'inverser les valeurs de 2 variables
//entières passées en argument par adresse et par référence

void inverse(int*a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void inverse(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
