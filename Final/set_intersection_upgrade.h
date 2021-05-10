#ifndef H_SET_INTERSECTION_UPGRADE
#define H_SET_INTERSECTION_UPGRADE
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class set_intersection_upgrade {

    public:
        template<class T>
        void set_intersection(vector<T> &v1, vector<T> &v2, vector<T> &vResults); // Default STL override to get rid of .begin() and .end()
        template<class T>
        void set_intersection(vector<T> &source, vector<T> &destination); // Ability to do a 3rd, 4th, 5th intersect in one line of code

};

template<class T>
void set_intersection(vector<T> &v1, vector<T> &v2, vector<T> &vResults) {
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(vResults));
}

template<class T>
void set_intersection(vector<T> &source, vector<T> &destination) {
    vector<T> flushVector;
    std::set_intersection(source.begin(), source.end(), destination.begin(), destination.end(), back_inserter(flushVector));
    destination.clear();
    destination = flushVector;
    flushVector.clear();
}

#endif