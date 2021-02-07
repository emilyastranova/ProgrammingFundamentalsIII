// Header file: myStack.h
#ifndef H_StackType
#define H_StackType

#include <cassert>
#include <iostream>

#include "stackADT.h"

using namespace std;

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *link;
};

template <class Type>
class stackType : public stackADT<Type>
{
public:
    const stackType<Type> &operator=(const stackType<Type> &);
    // Overload the assignment operator.

    void initializeStack();
    // Function to initialize the stack to an empty state.
    // Postcondition: stackTop = 0

    bool isEmptyStack() const;
    // Function to determine whether the stack is empty.
    // Postcondition: Returns true if the stack is empty,
    //               otherwise returns false.

    bool isFullStack() const;
    // Function to determine whether the stack is full.
    // Postcondition: Returns true if the stack is full,
    //               otherwise returns false.

    void push(const Type &newItem);
    // Function to add newItem to the stack.
    // Precondition: The stack exists and is not full.
    // Postcondition: The stack is changed and newItem
    //               is added to the top of the stack.

    Type top() const;
    // Function to return the top element of the stack.
    // Precondition: The stack exists and is not empty.
    // Postcondition: If the stack is empty, the program
    //               terminates; otherwise, the top element
    //               of the stack is returned.

    void pop();
    // Function to remove the top element of the stack.
    // Precondition: The stack exists and is not empty.
    // Postcondition: The stack is changed and the top
    //               element is removed from the stack.

    stackType();
    //Default constructor
    //Postcondition: stackTop = nullptr;

    stackType(const stackType<Type> &otherStack);
    // copy constructor

    ~stackType();
    // destructor
    // Remove all the elements from the stack.
    // Postcondition: The array (list) holding the stack elements is deleted.

private:
    nodeType<Type> *stackTop; // variable to point to the top of the stack
    Type *list;               // pointer to the array that holds the stack elements

    void copyStack(const stackType<Type> &otherStack);
    // Function to make a copy of otherStack.
    // Postcondition: A copy of otherStack is created and assigned to this stack.
};

// initializeStack
template <class Type>
void stackType<Type>::initializeStack()
{
    nodeType<Type> *temp;       //pointer to delete the node
    while (stackTop != nullptr) //while there are elements in the stack
    {
        temp = stackTop;           //set temp to point to the current node
        stackTop = stackTop->link; //advance stackTop to the next node
        delete temp;               //deallocate memory occupied by temp
    }
}

// isEmptyStack
template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return (stackTop == nullptr);
}

// isFullStack
template <class Type>
bool stackType<Type>::isFullStack() const
{
    return false;
}

// push
template <class Type>
void stackType<Type>::push(const Type &newItem)
{
    nodeType<Type> *newNode;      //pointer to create the new node
    newNode = new nodeType<Type>; //create the node
    newNode->info = newItem;   //store newElement in the node
    newNode->link = stackTop;     //insert newNode before stackTop
    stackTop = newNode;           //set stackTop to point to the top node
}

// top
template <class Type>
Type stackType<Type>::top() const
{
    assert(stackTop != nullptr); // if stack is empty, terminate the program

    return stackTop->info; // return the element of the stack indicated by stackTop - 1
}

// pop
template <class Type>
void stackType<Type>::pop()
{
    nodeType<Type> *temp; //pointer to deallocate memory
    if (stackTop != nullptr)
    {
        temp = stackTop;           //set temp to point to the top node
        stackTop = stackTop->link; //advance stackTop to the next node
        delete temp;               //delete the top node
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}

template <class Type>
stackType<Type>::stackType()
{
    stackTop = nullptr;
}

template <class Type>
stackType<Type>::~stackType()
{                  // destructor
    initializeStack();
}

// copyStack
template <class Type>
void stackType<Type>::copyStack(const stackType<Type> &otherStack)
{
    nodeType<Type> *newNode, *current, *last;
    if (stackTop != nullptr) //if stack is nonempty, make it empty
        initializeStack();
    if (otherStack.stackTop == nullptr)
        stackTop = nullptr;
    else
    {
        current = otherStack.stackTop; //set current to point
        //to the stack to be copied
        //copy the stackTop element of the stack
        stackTop = new nodeType<Type>;  //create the node
        stackTop->info = current->info; //copy the info

        stackTop->link = nullptr; //set the link field of the node to nullptr
        last = stackTop;         //set last to point to the node
        current = current->link; //set current to point to the next node
        //copy the remaining stack
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;
            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        } //end while
    }     //end else
}

// copy constructor
template <class Type>
stackType<Type>::stackType(const stackType<Type> &otherStack)
{
    stackTop = nullptr;
    copyStack(otherStack);
}

// operator=
template <class Type>
const stackType<Type> &stackType<Type>::operator=(
    const stackType<Type> &otherStack)
{
    if (this != &otherStack)
    { // avoid self-copy
        copyStack(otherStack);
    }
    return *this;
}

#endif