/*
Écrire plus simplement en C++ les instructions suivantes, en utilisant les opérateurs new, new[], delete et
delete[] :

void essai_alloc(){
int* pt_int;
double* pt_double;
pt_int=(int*)malloc(sizeof(int));
pt_double=(double*)malloc(sizeof(double)*100);
free(pt_int);
free(pt_double);
}

 */

void essai_alloc(){
    int* pt_int = new int;
    double* pt_double = new double[100];
    delete pt_int;
    delete[] pt_double;
}
