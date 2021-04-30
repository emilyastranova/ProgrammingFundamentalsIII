#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

mutex mtx;

void print(int n, const std::string &str) {
    std::string msg = std::to_string(n) + " : " + str;
    mtx.lock();
    std::cout << msg;
    std::cout << std::endl;
    mtx.unlock();
}

int main() {
    std::vector<std::string> s = {
        "thread 00",
        "thread 01",
        "thread 02",
        "thread 03",
        "thread 04",
        "thread 05",
        "thread 06",
        "thread 07",
        "thread 08",
        "thread 09"};
    std::vector<std::thread> threads;

    for (int i = 0; i < s.size(); i++) {
        threads.push_back(std::thread(print, i, s[i]));
    }

    for (auto &th : threads) {
        th.join();
    }
    return 0;
}
