#include <iostream>
#include <thread>
#include <list>
#include <mutex>

using namespace std;

// a global variable
std::list<int> myList;
mutex mtx;

void addToList(int max, int interval) {
    lock_guard<mutex> guard(mtx);
    for (int i = 0; i < max; i++) {
        if ((i % interval) == 0) {
            myList.push_back(i);
        }
    }
}

void printList() {
    // the access to this function is mutually exclusive
    
    for (auto itr = myList.begin(), end_itr = myList.end(); itr != end_itr; ++itr) {
        cout << *itr << ",";
    }
}

int main() {
    int max = 100;

    std::thread t1(addToList, max, 1);
    std::thread t2(addToList, max, 10);
    std::thread t3(printList);

    t1.join();
    t2.join();
    if(t3.joinable())
        t3.join();

    return 0;
}