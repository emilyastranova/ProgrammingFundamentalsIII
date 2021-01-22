// Blinn College : COSC 2436 Fall 2020
// Lab01 - add described functionality to testLinkedList
// sample input : 22 34 56 2 89 90 0 14 56 11 43 55 -999

#include <iostream>

#include "unorderedLinkedList.h"

using namespace std;

int main() {
    unorderedLinkedList<int> list;

    int num;

    cout << "Enter numbers ending with -999" << endl;
    cin >> num;

    while (num != -999) {
        list.insertLast(num);
        cin >> num;
    }

    cout << endl;

    cout << "List: ";
    list.print();
    cout << endl;
    cout << "Length of the list: " << list.length() << endl;


    // lab01 part a - find and delete the node with the smallest info
    // (Completed) todo : list.deleteSmallest();
    list.deleteSmallest();
    cout << "List after deleting the smallest element" << endl;
    list.print();
    cout << endl;

    // lab01 part b - Find and delete all occurrences of a given info
    cout << "Enter number to delete all occurrences of : ";
    cin >> num;
    cout << endl;
    
    // (Completed) todo : list.deleteAll(num);
    list.deleteAll(num);
    cout << "List after deleting all occurrences of " << num << endl;
    list.print();
    cout << endl;

    // lab01 part c - Find and delete all occurrences of a given info
    int k = 0;
    int temp = 0;

    cout << "Enter the position of the item to be retrieved: " << endl;
    cin >> k;
    cout << endl;

    // todo : temp = list.getKThElement(k);
    cout << "Item at position " << k << " = " << temp << endl;

    // lab01 part d - deletes the kth element of the linked list. 
    //                If no such element exists, terminate the program
    cout << "Enter the position of the item to be removed: " << endl;
    cin >> k;
    cout << endl;

    // todo : list.deteteKthElement(k);

    cout << "List after removing the element at position " << k << "." << endl;
    list.print();
    cout << endl;

    return 0;
}