#include <stdio.h>
#include <time.h>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

#include "../set_intersection_upgrade.h"
#include "wikiEntry.h"

int main() {
    vector<wikiEntry> entries;
    readInData(entries);

    vector<wikiEntry> currentVector;
    vector<wikiEntry> resultsVector;
    vector<wikiEntry>::iterator resultIterator;

    clock_t t;

    while (1) {
        // Get user input
        vector<string> userInput;
        getUserInput(userInput);
        vector<string>::iterator userInputIt = userInput.begin();

        t = clock();  // We liked this code a lot: https://www.tutorialspoint.com/how-to-measure-time-taken-by-a-function-in-c
        // Handle the first (or only) word
        searchString(entries, *userInputIt, resultsVector);
        ++userInputIt;

        if (userInputIt != userInput.end()) {  // Handle anything more than 1 words (loop)
            for (userInputIt; userInputIt != userInput.end(); ++userInputIt) {
                searchString(entries, *userInputIt, currentVector);
                set_intersection(currentVector, resultsVector);
            }
        }

        // Print final results
        printEntryVector(resultsVector);
        t = clock() - t;
        double time_taken = ((double)t) / CLOCKS_PER_SEC;  // calculate the elapsed time
        printf("The program took %f seconds to execute\n", time_taken);
        userInput.clear();
        currentVector.clear();
        resultsVector.clear();
    }
    return 0;
}
