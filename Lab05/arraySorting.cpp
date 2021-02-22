#include <iostream>
#include <iomanip>

#include "searchSortAlgorithms.h"

using namespace std;

void fillArray(int list[], int length);
void copyArray(int list1[], int list2[], int length);
const int sizeArray = 5000;

int main() {
    int list1[sizeArray];
    int list2[sizeArray];
    int list3[sizeArray];
    int list4[sizeArray];
    int list5[sizeArray];

    int compBubbleSort = 0, compSelectionSort = 0, compInsertionSort = 0, compQuickSort = 0, compMergeSort = 0;
    int assignBubbleSort = 0, assignSelectionSort = 0, assignInsertionSort = 0, assignQuickSort = 0, assignMergeSort = 0;

    fillArray(list1, sizeArray);
    copyArray(list1, list2, sizeArray);
    copyArray(list1, list3, sizeArray);
    copyArray(list1, list4, sizeArray);
    copyArray(list1, list5, sizeArray);

    bubbleSort(list1, sizeArray, compBubbleSort, assignBubbleSort);
    selectionSort(list2, sizeArray, compSelectionSort, assignSelectionSort);
    insertionSort(list3, sizeArray, compInsertionSort, assignInsertionSort);
    
    cout << left << setw(15) << ""
        << right << setw(15) << "comparisons"
        << right << setw(15) << "assignments"
        << endl;
    
    cout << left << setw(15) << "bubble sort:"
        << right << setw(15) << compBubbleSort
        << right << setw(15) << assignBubbleSort
        << endl;

    cout << left << setw(15) << "selection sort:"
        << right << setw(15) << compSelectionSort
        << right << setw(15) << assignSelectionSort
        << endl;

    cout << left << setw(15) << "insertion sort:"
        << right << setw(15) << compInsertionSort
        << right << setw(15) << assignInsertionSort
        << endl;            

  return 0;
}

void fillArray(int list[], int length) {
    srand(time(0));

    for (int i = 0; i < length; i++) {
        list[i] = rand() % 100000 + 1;
    }
}

void copyArray(int list1[], int list2[], int length) {
    for (int i = 0; i < length; i++) { 
        list2[i] = list1[i];
    }
}
