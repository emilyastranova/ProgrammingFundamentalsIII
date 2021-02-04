#include <iostream>
#include "searchSortAlgorithms.h"
   
using namespace std;

const int LIST_LENGTH = 1000;

int main() {  
    int pos;                                        

    int list[LIST_LENGTH];
    for (int i = 0; i < LIST_LENGTH; i++) {
        list[i] = i * 2;
    }

    int searchItem = 0;
    int count;
    int countBin;

    while (1) {
        count = 0;
        countBin = 0;

        cout << endl << "search for: " ;
        cin >> searchItem;
        if(searchItem == -1)
            break;
        
        pos = seqSearch(list, LIST_LENGTH, searchItem, count);           

        if (pos != -1) {                                 
            cout << "linear search: " << searchItem << " found at position " << pos << endl;                        
        } else {                                         
            cout << "linear search: " << searchItem << " is not in list " << endl;
        }    
        cout << "Linear count: " << countBin << endl;
        
        pos = binarySearch(list, LIST_LENGTH, searchItem, countBin);           

        if (pos != -1) {                                 
            cout << "binary search: " << searchItem << " found at position " << pos << endl;                        
        } else {                                         
            cout << "binary search: " << searchItem << " is not in list " << endl;
        }    

        cout << "Binary count: " << countBin << endl;
    } 
    cout << "Program end";
    return 0;
}
