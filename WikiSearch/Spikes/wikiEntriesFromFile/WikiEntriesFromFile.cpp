#include <iostream>
#include <map>
#include <vector>
#include "../../wikiData.h"
#include "../wikiEntrySpike/wikiEntry.h"

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

    // Test having a map of wikiEntrys
    // map<title, wikiEntry datatype (including namespace and ID)>
    // Using wikiEntry function parseTitle() to avoid making another wikiEntry in memory ex. "wikiEntry(inputString).title"
    map<string, wikiEntry> entries;
    
    // Get input from the file
    wikiData row;
    while (file >> row) {
        insertEntry(entries, row[2], row[0], row[1]);
    }

    // Get user search query
    string userInput;
    while(1){
        cout << "Enter search query: ";
        cin >> userInput;
        if(userInput == "exit()")
            exit(1);
        // showing contents:
        map<string, wikiEntry>::iterator it = entries.begin();
        for (it = entries.begin(); it != entries.end(); ++it) {
            if (it->first.find(toLower(userInput)) != string::npos) {
                cout << "\nName: " << it->first << endl;
                cout << "NS: " << it->second.pairType.first << endl;
                cout << "ID: " << it->second.pairType.second << endl;
            }
        }
    
    }

}