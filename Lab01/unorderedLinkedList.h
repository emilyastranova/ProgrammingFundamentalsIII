#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList : public linkedListType<Type>
{
public:

    int getKThElement(const int k);

    void deleteAll(const Type &deleteItem);
    // Delete all occurences of num in list
    // Postcondition: Same as delete smallest except using num as filter

    void deleteSmallest();
    // Delete the smallest value in the list.
    // Postcondition: Previous link points to the node after the one deleted
    //                Node with smallest is assigned to a temp var and deleted from memory

    bool search(const Type &searchItem) const;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the
    //               list, otherwise the value false is
    //               returned.

    void insertFirst(const Type &newItem);
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is
    //               inserted at the beginning of the list,
    //               last points to the last node in the
    //               list, and count is incremented by 1.

    void insertLast(const Type &newItem);
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem
    //               is inserted at the end of the list,
    //               last points to the last node in the
    //               list, and count is incremented by 1.

    void deleteNode(const Type &deleteItem);
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing
    //               deleteItem is deleted from the list.
    //               first points to the first node, last
    //               points to the last node of the updated
    //               list, and count is decremented by 1.
};

template <class Type>
int unorderedLinkedList<Type>::getKThElement(const int k) {
    nodeType<Type>* current;  // pointer to traverse the list
    int count = 1;
    current = this->first;            // set current so that it points to the first node
    while (count != k) { // while more data to print
        current = current->link;
        count++;
    }
    return current->info;
}

template <class Type>
void unorderedLinkedList<Type>::deleteSmallest() {
    nodeType<Type>* current;  // pointer to traverse the list
    nodeType<Type>* smallest = this->first; // Set smallest value to first node

    current = this->first;            // set current so that it points to the first node
    while (current != nullptr) { // while more data to print
        if(current->info < smallest->info)
            smallest = current;
        current = current->link;
    }
    cout << "Smallest value was: " << smallest->info << endl << "Deleting first node containing: " << smallest->info << endl;
    deleteNode(smallest->info);
}

// I present to you... The lazy way of doing it! (Loop through every single time and delete if found)
// template <class Type>
// void unorderedLinkedList<Type>::deleteAll(const Type num) {
//     nodeType<Type>* current;  // pointer to traverse the list
//     int delCount = 0;
//     bool found = false;

//     current = this->first;            // set current so that it points to the first node
//     while (current != nullptr) { // while more data to print
//         found = false;
//         if(current->info == num){
//             delCount++; // Increase count of nodes deleted
//             found = true;
//         }
//         current = current->link;
//         if(found)
//             deleteNode(num);
//     }
//     cout << "Deleted " << delCount << " occurences of: " << num << endl;
// }

// Here is the proper way to do it in one pass
template <class Type>
void unorderedLinkedList<Type>::deleteAll(const Type &deleteItem) {
    nodeType<Type> *current;                //pointer to traverse the list
    nodeType<Type> *trailCurrent;           //pointer just before current
    nodeType<Type> *toBeDeleted;
    int delCount = 0;
                                        //search the list for the node with the given info
    trailCurrent = this->first;         //set trailCurrent to point to the first node
    current = this->first->link;        //set current to point to the second node

    while (current != nullptr) 
    {
        if(this->first->info == deleteItem){ // If the first element in the list needs deleting
            cout << "Item found was first. Deleting..." << endl;
            delCount++;
            toBeDeleted = this->first;
            trailCurrent= current; // Move tail forwards
            current = current->link; // Move current forwards
            this->count--;  // Reduce count of items in the list
            this->first = this->first->link; // Move first forwards
            delete toBeDeleted;                 //delete the node from the list
        }
        else if (current->info != deleteItem) { // If the current info isnt the item, keep going
            //cout << current->info << " is not the item" << endl;
            trailCurrent = current;
            current = current->link;
        } 
        else {                           // If item found
            delCount++;
            if(current == this->last){ // If we delete the last node we need to move it backwards
                cout << "Item deleted was last, moving last node backwards" << endl;
                this->last = trailCurrent;
                this->last->link = nullptr;
                cout << "Last node is now defined as value: " << this->last->info << endl << endl;
            }
            toBeDeleted = current;
            trailCurrent->link = current->link; // Move tail forwards
            current = current->link;
            this->count--;  // Reduce count of items in the list
            delete toBeDeleted;                 //delete the node from the list
        }
    }
    cout << "Deleted " << delCount << " occurences of: " << deleteItem << endl;
}

template <class Type>
bool unorderedLinkedList<Type>::search(const Type &searchItem) const {
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;

    current = this->first; //set current to point to the first
                           //node in the list

    while (current != nullptr && !found) //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found;
}

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type &newItem) {
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem; //store the new item in the node
    newNode->link = this->first;   //insert newNode before first
    this->first = newNode;         //make first point to the
                             //actual first node
    this->count++;                 //increment count

    if (this->last == nullptr) {  //if the list was empty, newNode is also the last node in the list
        this->last = newNode;
    }
}

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type &newItem) {
    nodeType<Type> *newNode;                //pointer to create the new node

    newNode = new nodeType<Type>;           //create the new node

    newNode->info = newItem;                //store the new item in the node
    newNode->link = nullptr;                //set the link field of newNode to nullptr

    if (this->first == nullptr) {                 //if the list is empty, newNode is both the first and last node
        this->first = newNode;
        this->last = newNode;
        this->count++;                      //increment count
    } else {                                //the list is not empty, insert newNode after last
        this->last->link = newNode;         //insert newNode after last
        this->last = newNode;               //make last point to the actual last node in the list
        this->count++;                      //increment count
    }
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type &deleteItem) {
    nodeType<Type> *current;                //pointer to traverse the list
    nodeType<Type> *trailCurrent;           //pointer just before current
    bool found;

    if (this->first == nullptr) {                 //Case 1; the list is empty.
        cout << "Cannot delete from an empty list." << endl;
    } else {
        if (this->first->info == deleteItem)      //Case 2
        {
            current = this->first;
            this->first = this->first->link;
            this->count--;
            if (this->first == nullptr) //the list has only one node
                this->last = nullptr;
            delete current;
        } else {                                //search the list for the node with the given info
            found = false;
            trailCurrent = this->first;         //set trailCurrent to point to the first node
            current = this->first->link;        //set current to point to the second node

            while (current != nullptr && !found) {
                if (current->info != deleteItem) {
                    trailCurrent = current;
                    current = current->link;
                } else {
                    found = true;
                }
            }

            if (found) {                        //Case 3; if found, delete the node
                trailCurrent->link = current->link;
                this->count--;

                if (this->last == current) {          //node to be deleted was the last node
                    this->last = trailCurrent;        //update the value of last
                }
                delete current;                 //delete the node from the list
            } else {
                cout << "The item to be deleted is not in " << "the list." << endl;
            }
        }
    }
}

#endif
