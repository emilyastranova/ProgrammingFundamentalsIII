//
// Created by William Hatcher on 4/23/21.
//

#include <utility>
#include <algorithm>

#include "wikiEntry.h"

int main() {
    vector<wikiEntry> wikiEntries = {
            makeEntry("43658487", "166067", "title"),
            makeEntry("300907853", "277592", "title"),
            makeEntry("66679025", "172583", "title"),
            makeEntry("233152987", "242099", "title"),
            makeEntry("207724733", "231119", "title"),
            makeEntry("89800554", "180741", "title"),
            makeEntry("247065992", "249093", "title"),
            makeEntry("231701098", "241714", "title"),
            makeEntry("212578740", "233342", "title"),
            makeEntry("240699153", "246147", "title"),
            makeEntry("265443003", "257621", "title"),
            makeEntry("133429249", "198058", "title"),
            makeEntry("123929477", "245107", "title"),
            makeEntry("348311637", "305183", "title"),
            makeEntry("203161898", "229147", "title"),
            makeEntry("123929477", "194323", "title"),
            makeEntry("239980909", "245795", "title"),
            makeEntry("43658487", "232817", "title"),
            makeEntry("354602575", "308096", "title"),
            makeEntry("182331940", "218844", "title"),
            makeEntry("265443003", "257654", "title")
    };

    for (const auto& item : wikiEntries ) {
        std::cout << item.pairType.first << ":" << item.pairType.second << endl;
    }

    sort(wikiEntries.begin(), wikiEntries.end());

    cout << endl << "AFTER SORT" << endl;
    for (const auto& item : wikiEntries ) {
        std::cout << item.pairType.first << ":" << item.pairType.second << endl;
    }
}