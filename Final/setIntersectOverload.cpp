#include <iostream>
#include <vector>
#include "set_intersection_upgrade.h"

using namespace std;

int main() {

    // Make vectors
    vector<int> v1 = {1,2,3,4,6};
    vector<int> v2 = {1,2,4,5,6};
    vector<int> v3 = {4,5,6,7,8};
    vector<int> v4 = {0,0,0,4,6};
    vector<int> vResults;

    // The original set intersection, STL version of set_intersection. Only uses v1 and v2
    // set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(vResults));

    // TODO: Modify the STL function to get rid of .begin() and .end() for readability
    set_intersection(v1, v2, vResults);

    // TODO: Do a set intersection with more than 2 using the new set_intersection function
    // Output should be "4 6" for given example
    set_intersection(v3, vResults);
    set_intersection(v4, vResults);
    

    // Print results
    cout << "Intersection values: ";
    for(auto i : vResults)
        cout << i << " ";
    cout << endl;

    return 0;
}