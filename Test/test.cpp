#include <iostream>
#include <vector>
#include <array>
#include <iterator>

using std::cout; using std::vector;
using std::endl; using std::array;
using std::copy;

int main() {
    vector<int> numbers {112, 105, 99, 111, 67, 84, 70, 123, 103, 48, 48, 100, 95, 107, 49, 116, 116, 121, 33, 95, 110, 49, 99, 51, 95, 107, 49, 116, 116, 121, 33, 95, 55, 99, 48, 56, 50, 49, 102, 53, 125, 10};
    vector<char> chars {};

    std::copy(numbers.begin(), numbers.end(),
                std::ostream_iterator<int>(cout, "; "));

    chars.reserve(numbers.size());
    for (auto &number : numbers) {
        chars.push_back(number);
    }
    cout << endl;
    std::copy(chars.begin(), chars.end(),
              std::ostream_iterator<char>(cout, ""));

    return EXIT_SUCCESS;
}