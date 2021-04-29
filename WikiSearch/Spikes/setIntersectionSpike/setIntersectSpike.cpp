#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <map>
#include "../wikiEntrySpike/wikiEntry.h"

using namespace std;

int main() {

    map<string, wikiEntry> entries;
    readInData(entries);
    vector<wikiEntry> v1, v2, vResult;
    vector<wikiEntry>::iterator resultIt;

    string userInput, userInput2;

    while(1){
        cout << "Enter search term: ";
        cin >> userInput;
        if(userInput == "exit")
            exit(1);
        cin >> userInput2;

        search(entries, userInput, v1);
        search(entries, userInput2, v2);

        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(vResult, vResult.begin()));

        printEntryVector(vResult);
        v1.clear(); v2.clear(); vResult.clear();
    }
    return 0;
}
