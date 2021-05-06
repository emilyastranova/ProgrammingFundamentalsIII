#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <thread>
#include <mutex>

#include "wikiData.h"

using namespace std;

vector<string> titles{};
mutex mtx;

std::istream& operator>>(std::istream& str, wikiData& data) {
    data.readNextRow(str);
    return str;
}

void addToQueue(string filename) {
    mtx.lock();
    std::ifstream file(filename);
    cout << file.fail() << endl;
    mtx.unlock();

    wikiData row;
    while (file >> row) {
        mtx.lock();
        titles.push_back(row[2]);
        cout << "[File: " << filename << "] - " << row[2] << endl;
        mtx.unlock();
    }
    
    cout << "titles count : " << titles.size() << endl;

}

int main() {
    int count = 0;

    thread t1(addToQueue, "wikiData0.dat");
    thread t2(addToQueue, "wikiData1.dat");

    t1.join();
    t2.join();

}
