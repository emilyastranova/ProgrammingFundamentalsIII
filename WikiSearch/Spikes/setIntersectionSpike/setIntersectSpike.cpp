#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <map>
#include "../wikiEntrySpike/wikiEntry.h"
#include "../../wikiData.h"

using namespace std;

istream& operator>>(istream& str, wikiData& data) {
    data.readNextRow(str);
    return str;
}

int main() {

    ifstream file("../wikiData.dat");
    if(file.fail()) {
        cout << "File failed to load" << endl;
        exit(1);
    }
    else
        cout << "wikiData loaded successfully!" << endl << endl;

    map<string, wikiEntry> entries;
    
    // Get input from the file
    wikiData row;
    while (file >> row) {
        insertEntry(entries, row[2], row[0], row[1]);
    }

 
    vector<wikiEntry> v1;
    vector<wikiEntry> v2;
    vector<wikiEntry> vResult;
    vector<wikiEntry>::iterator resultIt;

    string userInput;
    string userInput2;

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

        // Find longest result
        int longest = 0;
        for(resultIt = vResult.begin(); resultIt != vResult.end(); ++resultIt){
            if(resultIt->title.length() > longest)
                longest = resultIt->title.length();
        }

        if (vResult.empty())
            cout << "\nNo results found" << endl;
        else
            cout << "\nSearch Results:\n------------------\n";
            for(resultIt = vResult.begin(); resultIt != vResult.end(); ++resultIt){
                cout << resultIt->title << setw(8+longest-resultIt->title.length()) << "[NS] " << resultIt->pairType.first << setw(18-resultIt->pairType.first.length()) << "[ID] " << resultIt->pairType.second << endl;
            }
        cout << endl;
        v1.clear(); v2.clear(); vResult.clear();
    }
    return 0;
}
