#include <iostream>
#include <string>

#include "cityType.h"

using namespace std;

// mutators
void cityType::setStateID(string sid) {
    id = sid;
}
void cityType::setPlaceName(string pname){
    name = pname;
}
void cityType::setPlaceFIPS(string fips){
    placeFIPS = fips;
}
void cityType::setPopulation(int pop){
    population = pop;
}
void cityType::setGeolocation(string geo){
    geolocation = geo;
}

// accessors
string cityType::getID() {
    return id;
}
string cityType::getName(){
    return name;
}
string cityType::getPlaceFIPS(){
    return placeFIPS;
}
int cityType::getPopulation() {
    return population;
}
string cityType::getGeolocation(){
    return geolocation;
}

// relational operator overloads
bool cityType::operator!=(const cityType& right) const {
    return (this->placeFIPS != right.placeFIPS);
}
bool cityType::operator==(const cityType& right) const {
    return (this->placeFIPS == right.placeFIPS);
}