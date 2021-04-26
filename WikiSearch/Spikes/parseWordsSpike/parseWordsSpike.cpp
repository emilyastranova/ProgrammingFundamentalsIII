#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <map>
#include "../wikiEntrySpike/wikiEntry.h"
#include "../../wikiData.h"

using namespace std;

int main() {

    // Credit: paddy
    // https://stackoverflow.com/questions/14347033/reading-a-sequence-of-words-to-add-them-in-a-vector

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
