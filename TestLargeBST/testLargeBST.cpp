#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "binarySearchTree.h"

using namespace std;

int main() {
    bSearchTreeType<string> treeRoot;
    int num;
    int compareCount = 0;

    std::srand(std::time(nullptr));     // use current time as seed for random generator

    cout << "loading BST ..." << endl;

    unsigned long i = 0;
    while  (i < 100000000) {              // 100 million
  //while  (i < 100000) { 
        std::stringstream ss;
        ss << static_cast<char>(0x41 + (rand() % 26));    // position 0 = 'A'..'Z'
        ss << static_cast<char>(0x41 + (rand() % 26));    // position 1 = 'A'..'Z'
        ss << static_cast<char>(0x30 + (rand() % 10));    // position 2 = '0'..'9'
        ss << static_cast<char>(0x30 + (rand() % 10));    // position 3 = '0'..'9'
        ss << static_cast<char>(0x30 + (rand() % 10));    // position 4 = '0'..'9'
        ss << static_cast<char>(0x30 + (rand() % 10));    // position 5 = '0'..'9'
        ss << static_cast<char>(0x30 + (rand() % 10));    // position 6 = '0'..'9'
        ss << static_cast<char>(0x30 + (rand() % 10));    // position 7 = '0'..'9'
        ss << static_cast<char>(0x30 + (rand() % 10));    // position 8 = '0'..'9'
        ss << static_cast<char>(0x30 + (rand() % 10));    // position 9 = '0'..'9'
    
        if (treeRoot.insert(ss.str())) {                  // if not a duplicate 
            i++;
            if (i % 1000000 == 0) {
          //if (i % 1000 == 0) {
                cout << i << " " << ss.str() << endl;
           }
        }
    }

    cout << "loading BST complete" << endl;

    string key;    
    while (1) {                             // ^c to end
        cout << "search key: " ;
        cin >> key;
        cout << (treeRoot.search(key, compareCount) ? "found" : "not found") << endl;
        cout << "Comparisons: " << compareCount << endl;
    }

    return 0;
}
