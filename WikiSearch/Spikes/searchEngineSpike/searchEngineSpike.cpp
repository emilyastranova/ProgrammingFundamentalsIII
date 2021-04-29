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

    // Get input from the file
    map<string, wikiEntry> entries;
    readInData(entries);

    vector<vector<wikiEntry>> theMOAV; // The Mother of All Vectors
    vector<vector<wikiEntry>>::iterator moavIterator;
    vector<wikiEntry> vResult;
    vector<wikiEntry>::iterator vResultIt;
    vector<string> userSearchTerms;
    vector<string>::iterator userSearchIt;
    

    // Credit: paddy
    // https://stackoverflow.com/questions/14347033/reading-a-sequence-of-words-to-add-them-in-a-vector
    //-------------------------------------------------------
    // Get all words on one line                            |
    cout << "Enter search term: " << flush; //              |
    string allwords; //                                     |
    getline(cin, allwords); //                              |
    //                                                      |
    // Parse words into a vector                            |
    string word; //                                         |
    istringstream iss(allwords); //                         |
    while( iss >> word ) userSearchTerms.push_back(word);// |
    //-------------------------------------------------------

    // 

    userSearchIt = userSearchTerms.begin(); // Iterator for all the search terms
    moavIterator = theMOAV.begin(); // Iterator for the vector of results

    for(userSearchIt = userSearchTerms.begin(); userSearchIt != userSearchTerms.end(); ++userSearchIt) {
        theMOAV.insert(theMOAV.begin(), vector<wikiEntry>());
        moavIterator = theMOAV.begin(); // Move the MOAV iterator forwards for next result
        search(entries, *userSearchIt, *moavIterator); // Store results in a vector of wikiEntries in the MOAV
    }

    // This code is bad
    moavIterator = theMOAV.begin(); // Outside the MOAV
    vResultIt = (*moavIterator).begin(); // Inside the MOAV
    if (theMOAV.empty())
        cout << "\nNo results found" << endl;
    else
        cout << "\nSearch Results:\n------------------\n";
        for(moavIterator = theMOAV.begin(); moavIterator != theMOAV.end(); ++moavIterator){
            cout << "Results for: " << (*moavIterator).begin()->title << endl;
            sort((*moavIterator).begin(), (*moavIterator).end());
            for(vResultIt = (*moavIterator).begin(); vResultIt != (*moavIterator).end(); ++vResultIt)
                cout << vResultIt->title << " [NS] " << vResultIt->pairType.first << " [ID] " << vResultIt->pairType.second << endl;
            cout << "-------------------------------------" << endl;
        }
    cout << endl;

    // TODO: This needs to be infinite
    //sort(v1.begin(), v1.end());
    //set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(vResult, vResult.begin()));

    // This code is bad
    moavIterator = theMOAV.begin();
    vector<wikiEntry> temp = (*moavIterator);
    ++moavIterator;
    vector<wikiEntry> temp2 = (*moavIterator);
    ++moavIterator;
    set_intersection(temp.begin(), temp.end(), temp2.begin(), temp2.end(), inserter(vResult, vResult.begin()));
    printEntryVector(vResult);

    return 0;
}
