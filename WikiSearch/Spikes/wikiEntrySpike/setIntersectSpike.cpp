#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main() {

    map<string, string> wikiTitles;

    // wikiTitles.insert(pair<string, string>("howdy", "101"));
    // wikiTitles.insert(pair<string, string>("texas", "102"));
    // wikiTitles.insert(pair<string, string>("howdy", "103"));

    wikiTitles["howdy"] = "101";
    wikiTitles["texas"] = "102";
    wikiTitles["howdy"] = "103";

    map<string, string>::iterator it = wikiTitles.begin();

    // showing contents:
    for (it = wikiTitles.begin(); it != wikiTitles.end(); ++it) {
        cout << it->first << " => " << it->second << endl;
    }

    vector<int> v1 = {5, 10, 15, 20, 50};
    vector<int> v2 = {50, 40, 30, 20, 5};
    set<int> vResult;

    ostream_iterator<int> screen(cout, " ");

    cout << "v1 = ";
    copy(v1.begin(), v1.end(), screen);
    cout << endl;

    cout << "v2 = ";
    copy(v2.begin(), v2.end(), screen);
    cout << endl;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(vResult, vResult.begin()));
    cout << "\nIntersecting values:\n";
    copy(vResult.begin(), vResult.end(), screen);

    return 0;
}
