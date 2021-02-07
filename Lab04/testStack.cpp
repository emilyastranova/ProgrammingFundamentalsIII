// Program to test the various operations of a stack
#include <iostream>

#include "stackType.h"

using namespace std;

int main() {
    stackType<int> stack;
    stackType<int> copyStack;

    stack.initializeStack();
    stack.push(85);
    stack.push(28);
    stack.push(56);

     cout << "Testing assignment operator: " << endl;
     copyStack = stack;          // copy stack into copyStack using assignment overload

    cout << "The elements of copyStack: (should be 56 28 85): ";
    while (!copyStack.isEmptyStack()) { // print copyStack
        cout << copyStack.top() << " ";
        copyStack.pop();
    }
    cout << endl;

    cout << "Testing copy constructor: " << endl;
    copyStack = stack;
    stackType<int> copyConstructedStack = stack;        // call the copy constructor

    cout << "The elements of copyConstructedStack (should be 56 28 85): ";
    while (!copyConstructedStack.isEmptyStack()) { // print stack
        cout << copyConstructedStack.top() << " ";
        copyConstructedStack.pop();
    }
    cout << endl;

    return 0;
}


