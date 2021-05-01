#include <algorithm>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <vector>
#include <map>
#include "../wikiEntrySpike/wikiEntry.h"

using namespace std;

int main() {

    // Get input from the file
    map<string, wikiEntry> entries;
    readInData(entries);

    vector<string> userSearchTerms; vector<string>::iterator userSearchIt;
    
    vector<wikiEntry> flushVector;
    vector<wikiEntry> currentVector;
    vector<wikiEntry> vResult;
    bool singleWord = false;

    while(1) {
        // Get user search terms and store in a vector of strings
        getUserInput(userSearchTerms);
        userSearchIt = userSearchTerms.begin(); // Iterator for all the search terms

        // Iterate through the terms and set intersect at the same time... Oh god why
        /*
            1) Search through first term 
            2) Store the results in a vector (flushVector). Only using this once, then it becomes a swap 
            3) Search through second term
            4) Temporarily store in another vector (currentVector)
            5) Only store the intersecting values vResults
            6) Move currentVector forwards
            7) Do set_intersection on vResults and currentVector
            8) Store that in flushVector
            9) Clear vResults
            10) Move from flushVector to vResults
            11) Loop to step 5
        */ 

        if((*userSearchIt) == "exit")
            exit(0);
        // First runtime
        search(entries, *userSearchIt, flushVector);
        ++userSearchIt;

        // Handle a single word
        if(userSearchIt == userSearchTerms.end()) {
            singleWord = true;
            printEntryVector(flushVector);
        }

        if(!singleWord) {
            // Do the second word
            search(entries, *userSearchIt, currentVector);
            ++userSearchIt;
            sort(flushVector.begin(), flushVector.end()); sort(currentVector.begin(), currentVector.end());
            set_intersection(flushVector.begin(), flushVector.end(), currentVector.begin(), currentVector.end(), back_inserter(vResult));

            // Handle any other words
            for(userSearchIt; userSearchIt != userSearchTerms.end(); ++userSearchIt) {
                currentVector.clear();
                flushVector.clear();
                search(entries, *userSearchIt, currentVector);
                sort(vResult.begin(), vResult.end()); sort(currentVector.begin(), currentVector.end());
                set_intersection(currentVector.begin(), currentVector.end(), vResult.begin(), vResult.end(), back_inserter(flushVector));
                
                vResult.clear();
                vResult = flushVector;
                flushVector.clear();
            }
            
            // Print final results
            printEntryVector(vResult);
        }

        // Reset everything for the loop
        flushVector.clear(); currentVector.clear(); vResult.clear(); userSearchTerms.clear();
        singleWord = false;
    }

    return 0;
}