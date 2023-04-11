
#include <iostream>
using namespace std;
class Vector {
private:
    int tamano;
    int* array;

public:
    Vector() {
        tamano = 0;
        array = nullptr;
    }

    Vector(int n) {
        tamano = n;
        array = new int[tamano];
        for (int i = 0; i < n; i++) {
            array[i] = 0;
        }
    }
    void duplicar_tam() {
        int* copia = new int[tamano * 2];
        for (int i = 0; i < tamano * 2; i++) {
            if (i < tamano) { copia[i] = array[i]; }
            else { copia[i] = 0; }
        }
        array = copia;
        tamano = tamano * 2;

    }
    void dividir_tam() {
        int* copia = new int[tamano/2];
        for (int i = 0; i < tamano/2; i++) {
            if (i < tamano) { copia[i] = array[i]; }
            else { copia[i] = 0; }
        }
        array = copia;
        tamano = tamano / 2;

    }
    void mover_der() {
        int temp = 0;
        int temp2;
        for (int i = 0; i < tamano; i++) {
            temp2 = array[i];
            array[i] = temp;
            temp = temp2;
        }
    }

    void mover_izq() {

        for (int i = 0; i < tamano - 1; i++) {
            array[i] = array[i + 1];
        }
        array[tamano - 1] = 0;
    }
    void push_back(int n) {
        if (array[tamano - 1] != 0) {
            duplicar_tam();
        }
        for (int i = 0; i < tamano; i++) {
            if (array[i] == 0) { array[i] = n; i = tamano; }
        }
    }

    void push_front(int n) {
        if (array[tamano - 1] != 0) {
            duplicar_tam();
        }
        mover_der();
        array[0] = n;

    }
    void pop_front() {

        mover_izq();
        array[tamano] = 0;
        if (array[tamano / 2] == 0) { dividir_tam(); }

    }
    void pop_back() {
        int contador = 0;
        for (int i = tamano - 1; 0 <= i; i--) {
            if (contador == tamano / 2) { dividir_tam(); }
            contador++;
            if (array[i] != 0) {
                array[i] = 0;
                i = -1;
            }
        }

    }
    void print() {
        for (int i = 0; i < tamano; i++) {
            cout << array[i] << " ";
        }
    }
    int& operator[](int i) {
        return array[i];
    }
};

struct nodo
{
    int valor;
    nodo* next;
    nodo* back;
    nodo(int n)
    {
        valor = n;
        next = nullptr;
        back = nullptr;
    }
};


class List {
private:
    nodo* temp;
    nodo* primero;
    nodo* final;
public:
    List() {
        primero = nullptr;
        final = nullptr;
        temp = nullptr;
    }    
    void push_back (int i) {
        if (primero == nullptr) {
            temp =new nodo(i);
            primero = temp;
            final = temp;
        }
        else {
            temp = new nodo(i);
            final->next = temp;
            temp->back = final;
            final=temp;
        }

    }
    void push_front (int i){
        if (primero == nullptr) {
            temp = new nodo(i);
            primero = temp;
            final = temp;
        }
        else {
            temp = new nodo(i);
            temp->next = primero;
            primero->back = temp;
            primero = temp;
        }
    }
    void pop_back() {
        if (final != nullptr) {
            temp = final;
            final = final->back;
            if (final != nullptr) {
                final->next = nullptr;
            }
            else {
                primero = nullptr;
            }
            temp = nullptr;
        }
    }
    
    void pop_front() {
        if (primero != nullptr) {
            temp = primero;
            primero = primero->next;
            temp = nullptr;
            if (final != nullptr) {
                final->next = nullptr;
            }
            else {
                primero = nullptr;
            }
            temp = nullptr;
        }

    }
    void print() {
        temp = primero;
        while (temp != nullptr) {
            cout << temp->valor << " ";
            temp = temp->next;
        }
    }

    int& operator[](int i) {
        int contador = 0;
        temp = primero;
        while (temp != nullptr && contador < i) {
            temp =temp-> next;
            contador++;
        }
        return temp->valor;
    }   
};
int main()
{
    /*
    Vector v(4);
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(8);
    cout << v[1]<<"  "<<v[4]<<endl;
    v.push_front(7);
    v.print();
    cout << endl;
    v.push_front(9);
    v.print();
    cout << endl;
    v.push_front(10);
    v.print();
    cout << endl;
    v.pop_front();
    v.print();
    cout << endl;
    v.pop_front();
    v.print();
    cout << endl;
    v.pop_back();
    v.print();
    cout << endl;
    v.pop_front();
    v.print();
    cout << endl;
    v.pop_back();
    v.print();
    cout << endl;
    v.pop_front();
    v.print();
    cout << endl;
    v.pop_back();
    v.print();
    cout << endl;
    v.pop_front();
    v.print();
    cout << endl;
*/

    List* l = new List();
    l->push_front(15); l->print(); cout << endl;
    l->push_front(11); l->print(); cout << endl;
    l->push_front(12); l->print(); cout << endl;
    l->push_front(18); l->print(); cout << endl;
    l->push_back(8); l->print(); cout << endl;
    l->push_back(3); l->print(); cout << endl;
    l->push_back(5); l->print(); cout << endl;
    l->push_back(1); l->print(); cout << endl;
    cout << l->operator[](4) << endl;
    cout << (*l)[1] << endl;

    l->pop_back(); l->print(); cout << endl;
    l->pop_back(); l->print(); cout << endl;
    l->pop_back(); l->print(); cout << endl;
    l->pop_back(); l->print(); cout << endl;
    l->pop_back(); l->print(); cout << endl;
    l->pop_back(); l->print(); cout << endl;
    l->pop_back(); l->print(); cout << endl;
    l->pop_back(); l->print(); cout << endl;
    l->pop_back(); l->print(); cout << endl;
}

