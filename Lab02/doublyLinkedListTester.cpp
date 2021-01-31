// Program to test various operations on a doubly linked list
// Completed Lab 02! - Tyler Harrison
/*
1. Write the definitions of the functions for the class doublyLinkedList:
 [*]a. copyList
 [*]b. the copy constructor
 [*]c. function to overload the assignment operator 


2. Write a program to test various operations of the class doublyLinkedList. These test should include 
 [*]a. initializing the List
 [*]b. checking that list is empty when it should be and not empty when is not
 [*]c. prints correctly
 [*]d. correctly returns front and back elements when asked
 [*]e. correctly searches for elements
 [*]f. correctly inserts elements
 [*]g. correctly deletes elements ( empty, first, last, somewhere in the middle )
 [*]h. tests the new copy constructor 
 [*]i. tests the new assignment operator
*/
  
#include <iostream>
#include "doublyLinkedList.h"  
 
using namespace std;  

int main()
{
	cout << "Doubly Linked Lists Lab02 - Tyler Harrison" << endl << "------------------------" << endl;
	doublyLinkedList<int> dlList;
	// Test functions
	cout << "List 1: " << endl;
	for(int i = 1; i <= 10; i++)
		dlList.insert(i);
	dlList.print();

	cout << "\n------------------------" << endl;

	doublyLinkedList<int> list2;
	cout << "\nChecking if List 2 is empty... " << endl;
	if(list2.isEmptyList())
		cout << "List is empty" << endl;
	else
		cout << "List is populated" << endl;
	
	cout << "Populating List 2 by copying from List 1..." << endl;
	list2.copyList(dlList);
	cout << "\nList 2 (after copyList() function): " << endl;
	list2.print();
	cout << "\nChecking if List 2 is empty... " << endl;
	if(list2.isEmptyList())
		cout << "List is empty" << endl;
	else
		cout << "List is populated" << endl;
	
	cout << "\nList 2 printed in reverse: " << endl;
	list2.reversePrint();

	cout << "\n------------------------" << endl;

	cout << "\nList 3 (copied from List 2 using constructor): " << endl;
	doublyLinkedList<int> list3 = doublyLinkedList<int>(list2);
	list3.print();
	cout << "\nInserting #4 into List 3..." << endl;
	list3.insert(4);
	list3.print();

	cout << "\n------------------------" << endl;

	cout << "\nList 4 (copied from List 3 using assignment): " << endl;
	doublyLinkedList<int> list4 = list3;
	list4.print();

	cout << "\n------------------------" << endl;

	// Run insertion and deletion tests
	cout << "\nDeleting #1 in List 4..." << endl;
	list4.deleteNode(1);
	cout << "Deleting #10 in List 4..." << endl;
	list4.deleteNode(10);
	cout << "Deleting #5 in List 4..." << endl;
	list4.deleteNode(5);
	list4.print();

	cout << "\n------------------------" << endl;

	cout << "\nSearching for the number 3..." << endl;
	if(list4.search(3))
		cout << "Number 3 was found!" << endl;
	else
		cout << "Number 3 was not found" << endl;
	
	cout << "\nSearching for the Answer to the Ultimate Question of Life, the Universe, and Everything" << endl;
	if(list4.search(42))
		cout << "Number 42 was found!" << endl;
	else
		cout << "Number 42 was not found" << endl;

	cout << "\n------------------------" << endl;

	cout << "Front of List 4 is " << list4.front() << endl;
	cout << "Back of List 4 is " << list4.back() << endl;
	cout << "\nProgram complete" << endl;
	return 0;
} 
