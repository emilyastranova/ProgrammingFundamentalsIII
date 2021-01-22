#include <iostream>

using namespace std;

struct nodeType {
    int info;       // Data inside the node
    nodeType *link; // Address of the next element

    void printInfo() {cout << info << endl;}
    void printLink() {cout << link << endl;}
};

int main(){
    nodeType *head, *n1, *n2; // Init the head and nodes

    head = new nodeType;

    n1 = new nodeType;
    n1 -> info = 12;

    head -> link = n1; // Same as (*head).link = n1;

    n2 = new nodeType;
    n1 -> link = n2;
    n2 -> info = 24;
    n2 -> link = nullptr;

    cout << "Head Addr: " << head << endl;
    cout << "Head link points to: ";
    (*head).printLink();

    cout << "\nNode 1 Addr: " << n1 << endl;
    cout << "Node 1 Value: "; 
    (*n1).printInfo();
    cout << "Node 1 points to: ";
    (*n1).printLink();

    cout << "\nNode 2 Addr: " << n2 << endl;
    cout << "Node 2 Value: "; 
    (*n2).printInfo();
    cout << "Node 2 points to: " << n2->link;
    return 0;
}