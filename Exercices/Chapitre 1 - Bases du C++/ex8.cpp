#include <iostream>
using namespace std;

int main()
{
    //Allocation mémoire
    int* pt = new int();
    *pt = 2;
    int *pt2 = new int(4);
    //Desallocation de la mémoire
    delete(pt);
    delete(pt2);
    return 0;
}
