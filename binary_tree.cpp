#include <iostream>
#define COUNT 10
using namespace std;
struct CNode {
    int v;
    CNode* nodes[2];
    CNode(int _v) {
        v = _v;
        nodes[0] = nodes[1] = NULL;
    }
};


class CBintree {
public:
    bool find(int x, CNode**& p);
    bool Insert(int x);
    bool remove(int x);
    void llama_print();
    void print(CNode* node,int space);
private:
    CNode* root =NULL;
};

bool CBintree::find(int x, CNode**& p) {
    p = &root;
    while (*p && (*p)->v != x) p = &((*p)->nodes[(*p)->v < x]);
    return *p != 0;
}

bool CBintree::Insert(int x) {
    CNode** p;
    if (find(x, p))return 0;
    *p = new CNode(x);
    return 1;
}

bool CBintree::remove(int x) {
    CNode** p;
    if (!find(x, p)) return 0;

    if ((*p)->nodes[0] != NULL && (*p)->nodes[1] != NULL) {
        CNode* temp = (*p)->nodes[0];
        CNode* temp2 = temp;
        while (temp->nodes[1] != NULL) { temp2 = temp; temp = temp->nodes[1];  }
        (*p)->v = temp->v;
        temp2->nodes[1]=nullptr;
    }

    //Creo q puedo resumirlos mucho mas como pa q esten en un solo else if 
    else if ((*p)->nodes[0] == NULL && (*p)->nodes[1] != NULL) {
        (*p)->v = (*p)->nodes[1]->v;
        (*p)->nodes[1]=nullptr;
    }
    else if ((*p)->nodes[1] == NULL && (*p)->nodes[0] != NULL) {
        (*p)->v = (*p)->nodes[0]->v;
        (*p)->nodes[0]=nullptr;
    }
    else (*p)= nullptr;

    return 1;
}

void CBintree::llama_print() {
    // Pass initial space count as 0
    print(root, 0);
}
void CBintree::print(CNode* node, int space)
{
    // Base case
    if (node == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first if it exists
    if (node->nodes[1] != NULL) {
        print(node->nodes[1], space);
    }

    // Print current node after space count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << node->v << "\n";

    // Process left child if it exists
    if (node->nodes[0] != NULL) {
        print(node->nodes[0], space);
    }
}





int main()
{

    CBintree arbolin;   
    arbolin.Insert(5);
    arbolin.Insert(10);
    arbolin.Insert(3);
    arbolin.Insert(4);
    arbolin.Insert(11);
    arbolin.Insert(8);
    arbolin.Insert(9);
    arbolin.Insert(14);
    arbolin.Insert(1);
    arbolin.Insert(2);
    arbolin.llama_print();
    cout << endl << endl << endl;
    arbolin.remove(5);
    arbolin.llama_print();
    cout << endl << endl << endl;
    arbolin.remove(8);
    arbolin.llama_print();
    cout << endl << endl << endl;
    arbolin.remove(14);
    arbolin.llama_print();
    cout << endl << endl << endl;
    arbolin.remove(10);
    arbolin.llama_print();
    cout << endl << endl << endl;
    arbolin.remove(1);
    arbolin.llama_print();
    cout << endl << endl << endl;
}
