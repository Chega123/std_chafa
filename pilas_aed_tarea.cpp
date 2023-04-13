#include <iostream>
using namespace std;

class Cola {
    int A[10];
    int* inicio = A + 9, * fin = A, * head = nullptr, * tail = nullptr;
public:
    /*
    void mover_der() {
        int temp = 0;
        int temp2;
        for (int i = 0; i < 10; i++) {
            temp2 = A[i];
            A[i] = temp;
            temp = temp2;
        }
    }
    */
    void push(int x) {
        if (head) {
         
            if (tail == nullptr) { tail = inicio; }
            tail--;
            if(head == tail){
                cout << "tail alcanzo head" << endl << "la pila esta llena" << endl;
                head = nullptr;
                tail = nullptr;
                return;
            }
            if (tail < fin && head != inicio) {
                tail = inicio;
            }
            *tail = x;


        }
        else {
            head = inicio;
            *head = x;
        }
    }
    void pop() {
        if (head) {
            int* temp = head;
            head--;
            if (temp == tail) {
                *temp = NULL;
                cout << "head alcanzo tail" << endl;
                head = nullptr;
                tail = nullptr;
                return;
            }
            if (head < fin && tail != inicio) {
                head = inicio;
            }
            *temp = NULL;
        }
        else cout << "cola vacia" << endl;
  }
    void print() {
        for (int i = 0; i < 10; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Cola colita;
      
    colita.push(1);
    colita.print();
    colita.push(2);
    colita.print();
    colita.push(3);
    colita.print();
    colita.push(4);
    colita.print();
    colita.push(5);
    colita.print();
    colita.push(6);
    colita.print();
    colita.push(7);
    colita.print();
    colita.push(8);
    colita.print();
    colita.push(9);
    colita.print();
    colita.push(10);
    colita.print();
    colita.pop();
    colita.print();
    colita.push(11);
    colita.print();
    colita.pop();
    colita.print();
    colita.push(12);
    colita.print();
    colita.pop();
    colita.print();
    colita.push(13);
    colita.print();
    colita.pop();
    colita.print();
    colita.push(14);
    colita.pop();
    colita.print();
    colita.push(15);
    colita.pop();
    colita.print();
    colita.push(16);
    colita.pop();
    colita.print();
    colita.push(17);
    colita.pop();
    colita.print();
    colita.push(18);
    colita.pop();
    colita.print();
    colita.push(19);
    colita.pop();
    colita.print();
    colita.push(20);
    colita.pop();
    colita.print();
    colita.push(21);
    colita.pop();
    colita.print();
    colita.push(22);
    colita.push(23);
    colita.print();

}

