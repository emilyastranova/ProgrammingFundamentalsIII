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

    // Get all words on one line
    cout << "Enter search term: " << flush;
    string allwords;
    getline(cin, allwords);

    // Parse words into a vector
    vector<string> words;
    string word;
    istringstream iss(allwords);
    while( iss >> word ) words.push_back(word);

    vector<string>::iterator it = words.begin();

    for(it = words.begin(); it != words.end(); ++it)
        cout << *it << endl;

    return 0;
}
