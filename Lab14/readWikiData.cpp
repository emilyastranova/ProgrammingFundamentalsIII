#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <mutex>

#include "wikiData.h"

using namespace std;

vector<string> titles{};
mutex mtx;

std::istream& operator>>(std::istream& str, wikiData& data) {
    data.readNextRow(str);
    return str;
}

int main() {
    int count = 0;

    std::ifstream file("wikiData0.dat");
    
    std::cout << file.fail() << std::endl;

    wikiData row;
    while (file >> row) {
        titles.push_back(row[2]);
    }
    
    for (const auto &t : titles) {
        cout << t << endl;
    }
    cout << "titles count : " << titles.size() << endl;
}
