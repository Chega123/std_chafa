#include <iostream>
using namespace std;


// sacar total de datos (numero de bytes/4)
void merge(int* p, int* q, int tamano) {
    int temp;
    
    for (; q<p+tamano; q++) {
        for (int *i= p; i < q; i++) {
            if (*i > *q) {
                temp = *i;
                *i = *q;
                *q = temp;
            }
        }
    }
}

int main() {

    int A[8] = { 4,16,20,32,3,7,11,25 };
    int valor;
    int tamano = sizeof(A) / sizeof(valor);
    int* p = A;
    int* q = A + (tamano/2);
    merge(p, q,tamano);

    for (int i = 0; i < tamano; i++) {
        cout << A[i] << "-";
    }
}
